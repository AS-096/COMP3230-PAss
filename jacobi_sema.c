#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>              /* For timing */
#include <sys/time.h>            /* For timing */
#include <sys/resource.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>


/****************Global****************************/

#define MAX(a,b) ((a)>(b)?(a):(b))
#define EPSILON 0.001            /* Termination condition */

char filename[50];                  /* File name of output file */

/* Grid size */
int M = 200;                     /* Number of rows */
int N = 200;                     /* Number of cols */
long max_its = 1000000;          /* Maximum iterations, a safe bound to avoid infinite loop */
double final_diff;               /* Temperature difference between iterations at the end */

/* Thread count */
int thr_count = 2;

/* shared variables between threads */
/*************************************************************/
double** u;                   /* Previous temperatures */
double** w;                   /* New temperatures */


// (1) Add your variables here
double diff = 0.00;
int done = 0;
sem_t arrayUpdateSem; // lock for the array and difference and finished threads
sem_t wakeupThreads1; // sem1 to wakeup threads
sem_t wakeupThreads2; // sem2 to wakeup threads (use alternately to avoid error)
sem_t wakeupMain; // sem to wakeup main

int finishedThreads = 0; // the number of threads that have finished their job

struct passInThreadsFunction {
   int fromRow;
   int toRow;
   double ***prv;
   double ***new;
};

/**************************************************************/

int main (int argc, char *argv[])
{
   int      its;                 /* Iterations to converge */
   double   elapsed;             /* Execution time */
   struct timeval stime, etime;  /* Start and end times */
   struct rusage usage;

   void allocate_2d_array (int, int, double ***);
   void initialize_array (double ***);
   void print_solution (char *, double **);
   int  find_steady_state (void);

   /* For convenience of other problem size testing */
   if ((argc == 1) || (argc == 4)) {
      if (argc == 4) {
         M = atoi(argv[1]);
         N = atoi(argv[2]);
         thr_count = atoi(argv[3]);
      } // Otherwise use default grid and thread size
   } else {
     printf("Usage: %s [ <rows> <cols> <threads> ]\n", argv[0]);
     exit(-1);
   }

   printf("Problem size: M=%d, N=%d\nThread count: T=%d\n", M, N, thr_count);

   /* Create the output file */
   sprintf(filename, "%s_%d_%d_%d.dat", argv[0], M, N, thr_count);

   allocate_2d_array (M, N, &u);
   allocate_2d_array (M, N, &w);
   initialize_array (&u);
   initialize_array (&w);

   gettimeofday (&stime, NULL);
   its = find_steady_state();
   gettimeofday (&etime, NULL);

   elapsed = ((etime.tv_sec*1000000+etime.tv_usec)-(stime.tv_sec*1000000+stime.tv_usec))/1000000.0;

   printf("Converged after %d iterations with error: %8.6f.\n", its, final_diff);
   printf("Elapsed time = %8.4f sec.\n", elapsed);

   /* get the resource usage of the whole process */
   getrusage(RUSAGE_SELF, &usage);
   printf("Program completed - user: %.4f s, system: %.4f s\n",
      (usage.ru_utime.tv_sec + usage.ru_utime.tv_usec/1000000.0),
    (usage.ru_stime.tv_sec + usage.ru_stime.tv_usec/1000000.0));
   printf("no. of context switches: vol %ld, invol %ld\n\n",
  		  usage.ru_nvcsw, usage.ru_nivcsw);

   print_solution (filename, w);
}

/* Allocate two-dimensional array. */
void allocate_2d_array (int r, int c, double ***a)
{
   double *storage;
   int     i;
   storage = (double *) malloc (r * c * sizeof(double));
   *a = (double **) malloc (r * sizeof(double *));
   for (i = 0; i < r; i++)
      (*a)[i] = &storage[i * c];
}

/* Set initial and boundary conditions */
void initialize_array (double ***u)
{
   int i, j;

   /* Set initial values and boundary conditions */
   for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++)
         (*u)[i][j] = 25.0;      /* Room temperature */
      (*u)[i][0] = 0.0;
      (*u)[i][N-1] = 0.0;
   }

   for (j = 0; j < N; j++) {
      (*u)[0][j] = 0.0;
      (*u)[M-1][j] = 1000.0;     /* Heat source */
   }
}

/* Print solution to standard output or a file */
void print_solution (char *filename, double **u)
{
   int i, j;
   char sep;
   FILE *outfile;

   if (!filename) { /* if no filename specified, print on screen */
      sep = '\t';   /* tab added for easier view */
      outfile = stdout;
   } else {
      sep = '\n';   /* for gnuplot format */
      outfile = fopen(filename,"w");
      if (outfile == NULL) {
         printf("Can't open output file.");
         exit(-1);
      }
   }

   /* Print the solution array */
   for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++)
         fprintf (outfile, "%6.2f%c", u[i][j], sep);
      fprintf(outfile, "\n"); /* Empty line for gnuplot */
   }
   if (outfile != stdout)
      fclose(outfile);

}

/* Entry function of the worker threads */
void *thr_func(void *arg) {
   // (2) Add the worker's logic here
   struct passInThreadsFunction* data = (struct passInThreadsFunction *) arg;
   // setup the borders first (no calculation for first and last row)
   if (data->fromRow == 0) data->fromRow = 1;
   if (data->toRow == M) data->toRow = M-1;
   // rows needed
   int rows = data->toRow - data->fromRow;
   int offset = data->fromRow; // offset of the first row of tmpArr w.r.t. the original arr
   // store the work here first
   double localDiff;
   double **prv;
   double **new;

   while (1) {
      // wait for work - next round
      /*****          state 1          *****/ 
      sem_wait(&wakeupThreads1);
      // terminate condition
      if (done == 1) {
         struct rusage* usage = malloc(sizeof(struct rusage));
         getrusage(RUSAGE_THREAD, usage);
         pthread_exit(usage);
      }
      localDiff = 0.00;
      // work on the thing with the given range
      prv = *(data->prv);
      new = *(data->new);
      for (int i = 0; i < rows; i++) {
         for (int j = 1; j < N-1; j++) {  // exclude first and last col 
            new[offset+i][j] = 0.25 * (prv[offset+i+1][j]+prv[offset+i-1][j]
               +prv[offset+i][j+1]+prv[offset+i][j-1]);
            if (fabs(new[offset+i][j] - prv[offset+i][j]) > localDiff)
               localDiff = fabs(new[offset+i][j] - prv[offset+i][j]);
         }
      }

      sem_wait(&arrayUpdateSem);
      if (localDiff > diff) diff = localDiff;
      finishedThreads++;
      // if all threads completed, wake up main to work
      if (finishedThreads == thr_count) sem_post(&wakeupMain); 
      sem_post(&arrayUpdateSem);

      /*****          state 2          *****/ // the same as state 1
      sem_wait(&wakeupThreads2);
      if (done == 1) {
         struct rusage* usage = malloc(sizeof(struct rusage));
         getrusage(RUSAGE_THREAD, usage);
         pthread_exit(usage);
      }
      localDiff = 0.00;
      prv = *(data->prv);
      new = *(data->new);
      for (int i = 0; i < rows; i++) {
         for (int j = 1; j < N-1; j++) {
            new[offset+i][j] = 0.25 * (prv[offset+i+1][j]+prv[offset+i-1][j]
               +prv[offset+i][j+1]+prv[offset+i][j-1]);
            if (fabs(new[offset+i][j] - prv[offset+i][j]) > localDiff)
               localDiff = fabs(new[offset+i][j] - prv[offset+i][j]);
         }
      }
      sem_wait(&arrayUpdateSem);
      if (localDiff > diff) diff = localDiff;
      finishedThreads++;
      if (finishedThreads == thr_count) sem_post(&wakeupMain); 
      sem_post(&arrayUpdateSem);
   }
}


int find_steady_state (void)
{
   // (3) Implement the thread creation and the main control logic here
   // init sems
   sem_init(&arrayUpdateSem, 0, 1);
   sem_init(&wakeupThreads1, 0, 0);
   sem_init(&wakeupThreads2, 0, 0);
   sem_init(&wakeupMain, 0, 0);
   // init and start threads
   struct passInThreadsFunction datas[thr_count];
   pthread_t threads[thr_count];
   // work out the rows numbers dedicated to each threads
   int averageRows = M / thr_count;
   int prvRow = 0;
   int rowsW1More = M - averageRows*thr_count;
   for (int i = 0; i < thr_count; i++) {
      datas[i].fromRow = prvRow;
      prvRow = (i < rowsW1More) ? prvRow+averageRows+1 : prvRow+averageRows;
      datas[i].toRow = prvRow;
      datas[i].prv = &u;
      datas[i].new = &w;
      pthread_create(&threads[i], NULL, thr_func, (void*)&datas[i]);
   }


   double **temp;
   int its = 0;
   // loop until max_its or converged
   for (;its < max_its; its++) {
      // wake thr_count threads to do work
      // alternate states to avoid threads going past semwait twice
      if (its % 2 == 0) {
         for (int i = 0; i < thr_count; i++) sem_post(&wakeupThreads1);
      } else {
         for (int i = 0; i < thr_count; i++) sem_post(&wakeupThreads2);
      }
      sem_wait(&wakeupMain);
      finishedThreads = 0;
      
      // swap u and w
      temp = u;
      u = w;
      w = temp;
      // printf("%d, %f\n", its, diff);
      // end work if converged to epsilon
      if (diff <= EPSILON) break;
      // printf("%f, %d\n", diff, its);
      diff = 0.00;
   }

   // set the flag to done, signaling threads to exit, then wake the threads up
   done = 1;
   if ((its+1) % 2 == 0) {
      for (int i = 0; i < thr_count; i++) sem_post(&wakeupThreads1);
   } else {
      for (int i = 0; i < thr_count; i++) sem_post(&wakeupThreads2);
   }

   // set final difference
   final_diff = diff;
   // cancel & join all threads and destroy all sems once its done
   struct rusage* usage;
   for (int i = 0; i < thr_count; i++) {
      pthread_join(threads[i], (void **) &usage);
      printf("Thread %d has completed - user: %.4f s, system: %.4f s\n", i,
         (usage->ru_utime.tv_sec + usage->ru_utime.tv_usec/1000000.0),
         (usage->ru_stime.tv_sec + usage->ru_stime.tv_usec/1000000.0));
      free(usage);
   }
   usage = malloc(sizeof(struct rusage));
   getrusage(RUSAGE_THREAD, usage);
   printf("find_steady_state - user: %.4f s, system: %.4f s\n",
      (usage->ru_utime.tv_sec + usage->ru_utime.tv_usec/1000000.0),
      (usage->ru_stime.tv_sec + usage->ru_stime.tv_usec/1000000.0));
   free(usage);

   sem_destroy(&arrayUpdateSem);
   sem_destroy(&wakeupThreads1);
   sem_destroy(&wakeupThreads2);
   sem_destroy(&wakeupMain);
   // return result
   return its+1;
}
