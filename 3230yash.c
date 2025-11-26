/**
 * @file 3230yash.c
 * @author AS-096
 * @brief 
 *      COMP3230 Programming Assignment 1 - YASH
 *      Student name and No: *****
 *      Development platform: 
 *          WSL2 on Windows 11 23H2 
 *          Distribution: Ubuntu 24.04.3 LTS
 *          Kernel: 5.10.16.3-microsoft-standard-WSL2
 *      Tested on Workbench2
 *      Remark(s): Every single function is implemented as requested.
 *                 Everything should work as intended.
 * 
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⢋⠻⢿⣿⣿⣿⣿⣿⣿⡿⡏⡡⡢⠌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⡃⢜⢜⢄⠛⣿⡿⡿⠟⠿⡉⡔⡕⡕⡭⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⢫⠻⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⢠⢣⢣⢣⢣⢢⢱⢰⢸⢸⢸⢸⢸⢸⢸⢐⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢸⣿⣷⣨⡛⡛⡛⡻⠻⢻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⡨⡪⡪⡪⡪⡪⡪⡪⢊⠊⠎⡎⡎⡎⡎⡎⡆⡍⢿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢩⣲⣿⢿⢿⣿⣿⣿⣿⣿⣷⣦⣝⣬⣴⣤⡙⣽⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡟⡃⡎⡎⡎⡎⡎⠎⣪⣴⣿⣿⣷⣶⡤⠥⣥⣡⣥⣴⡆⢻⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⡿⢍⣼⣿⣿⣭⣶⣾⣿⣿⣿⣿⣿⣿⣝⡙⢟⣿⡓⢥⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⡯⢱⣮⣬⣌⣬⣴⣶⢿⢴⣿⣿⣿⣿⣿⡟⢟⢿⣿⣿⣿⣯⢈⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡿⠍⣾⣿⣿⣿⠻⠛⢻⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⡇⢿⣿⣿⣿⣿⣿⠍⢰⢄⢹⣿⣿⣿⣿⠀⠲⠈⣻⣿⣿⣿⡂⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡟⣸⣿⣿⣿⣯⠠⡉⢠⣿⣿⣿⣿⡃⢥⡈⢹⣿⣿⣿⣿⡄⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⡇⣻⣿⣿⣿⣿⣿⡀⠒⢂⣼⢿⡿⣿⣿⣆⣉⡡⣟⣟⣟⢿⢀⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡇⣺⣟⢎⡚⡞⣖⣶⣟⠿⠝⢽⢿⣆⡐⣠⣼⣿⣿⣿⣿⣇⢺⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡄⢻⣿⡊⡌⡎⡏⡯⣿⣿⣍⢅⠌⣾⣿⣿⡧⣕⡶⡜⢁⢞⡛⢿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣯⠘⣿⣷⣗⣷⣼⣿⣿⣆⠳⣰⣿⣿⢯⢣⢓⢳⢓⣟⡿⡇⣺⣿⣿⣿⣿⣿
// ⠿⠿⠿⠿⠿⠿⠿⠦⠘⠽⠾⠽⠽⠽⠿⠿⠿⠬⠶⠿⠿⠿⠿⠿⠿⠾⠿⠿⠯⠸⠿⠿⠿⠿⠿⠸⠿⠿⠿⠿⠿⠿⠿⠷⢌⠻⠿⠝⢬⠪⠿⠿⠿⠿⠯⠫⡙⠽⠽⠽⠷⠷⠏⠴⠿⠿⠿⠿⠿⠿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⢙⢨⢰⠁⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠗⡡⡪⡪⡪⡪⡅⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡿⡿⡿⡿⡟⠏⡋⡍⡍⡔⡜⡜⡜⡜⡜⡜⡆⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⠏⡃⡅⡖⡒⡆⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡌⡫⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⢫⠻⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⡆⢣⢣⢣⢣⢣⢣⢣⢣⠣⢃⠣⠣⢣⢣⢣⢣⠣⡣⢃⣃⣤⠙⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢸⣿⣷⣨⡛⡛⡛⡻⠻⢻⢿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣄⠣⡣⡣⡣⡣⡣⡣⣱⣿⣿⣿⣶⣶⣦⣴⣶⣾⣿⣿⣿⣧⠸⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢩⣲⣿⢿⢿⣿⣿⣿⣿⣿⣷⣴⣹⣬⣴⣬⡜⣽⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡓⡸⡸⡸⢘⣤⣮⣼⣿⣿⣿⣿⣿⡏⣋⠙⢿⣿⣿⣿⣿⡄⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⡿⢍⣼⣿⣿⣭⣶⣾⣿⣿⣿⣿⣿⣿⣝⡙⠿⣿⡓⢥⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣗⢡⣮⣶⣾⣿⣟⠇⣁⠙⣿⣿⣿⣿⣆⠈⠆⣸⣻⢻⡻⣻⢂⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡿⠍⣾⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣗⢸⣿⣿⣿⣿⣷⠀⠤⢀⣿⢿⠊⠞⢿⣷⣿⡷⣜⢶⣝⡎⣰⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡟⣸⣿⣿⢿⣎⣀⣡⣿⣿⣿⣿⣿⣿⠝⠹⢿⢿⣿⣿⣿⡄⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡀⢿⣻⠹⡹⡹⡹⣺⣿⣿⣷⣎⠥⣿⣿⣿⢿⠿⡿⣿⡅⢿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡇⣺⣟⠎⡏⡯⢯⣻⣟⠿⠝⢽⢿⣿⣷⣶⣼⣿⣿⣿⣿⣇⢺⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣷⣌⠺⢵⣽⣽⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⠰⣷⣾⣼⣿⡔⣻⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣯⠘⣿⣽⣺⣮⣺⣺⣿⣞⣚⣶⣿⣿⣳⢱⢱⢳⢹⢽⣿⡓⣼⣿⣿⣿⣿⣿
// ⠿⠿⠿⠿⠿⠿⠿⢉⠶⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠧⠕⠿⠿⠿⢇⠺⠿⠿⠿⠿⠿⠿⠸⠿⠿⠿⠿⠿⠿⠿⠷⠌⠻⠿⠏⠮⡘⠿⠿⠿⠿⠯⠣⡙⠽⠽⠽⢝⢗⠗⠰⠿⠿⠿⠿⠿⠿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⡿⢩⢸⢸⢸⢸⢸⢰⢈⠻⢿⢿⠿⡿⡟⡛⡨⡰⡸⡸⡸⡄⠻⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⠫⣩⣩⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠟⡻⠻⣻⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⠓⡅⡇⡇⡇⡇⡇⡇⡇⡇⡇⡆⡆⡖⡔⡔⡕⡕⡕⡕⡕⡕⡝⡢⢹⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⡓⢼⣿⣿⣷⡌⢿⠻⠻⡛⣛⣙⡙⡛⡛⠟⢟⣨⣶⣿⣿⣷⠆⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⢃⢕⢕⢕⢕⢕⢕⢕⢕⢕⠕⠕⣑⣁⡃⠇⡇⡇⡇⡇⡇⡇⡇⡇⡗⡈⢿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣧⠹⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢛⣰⣿⣿⣿⣿⣿⣿
// ⣿⣿⣟⢣⣦⣑⡑⠕⡑⣑⣑⣡⣥⣴⣾⣿⣿⣿⣿⣷⣦⣅⣕⡑⠕⠕⡕⡕⡕⡕⡄⠻⣿⣿⣿⢸⣿⣿⣿⣿⡿⢩⣾⣿⣿⣿⡻⢹⣿⣿⣿⣿⣿⣿⣿⣯⣋⣻⣿⣿⣿⣿⣧⣙⢽⣿⣿⣿⣿⣿
// ⣿⡟⢢⣿⣿⣿⣿⣿⣿⣿⣿⣯⣋⣻⣿⣿⣿⣿⣿⣿⣿⣙⣹⣿⣷⣷⣶⣶⣶⣶⣶⣧⠹⣿⣿⢸⣿⣿⣿⡓⣥⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠹⣿⣿⣿⣿
// ⣿⠡⣿⣿⣿⣿⣿⣿⣿⣿⡟⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢹⣿⢸⣿⣿⡗⣴⣿⣿⣿⣿⣟⠃⣅⠫⢿⣿⣿⣿⣿⣿⣿⠛⢈⣌⠘⢽⣿⣿⣿⣿⣿⣇⢺⣿⣿⣿
// ⡓⣸⣿⣿⣿⣿⣿⣿⣿⡟⠀⠸⠒⠀⣻⣿⣿⣿⣿⣿⡯⠁⠴⠆⢘⣿⣿⣿⣿⣿⣿⣿⣿⡈⣿⢸⣿⣿⠅⣿⣿⣿⣿⣿⡂⠀⣉⡀⢸⣿⣿⣿⣿⣿⣿⠀⢀⡡⠀⢸⣿⣿⣿⣿⣿⣷⢘⣿⣿⣿
// ⡅⢾⣿⣿⡿⡿⣿⣻⡻⣷⡀⠐⠂⢠⣿⣿⣿⣿⣿⣿⣯⡀⠐⠂⣰⢿⢿⢿⢿⢿⣿⣿⣿⡆⢽⢸⣿⣿⡕⣿⣿⡿⡿⣟⢷⣄⣠⣤⣿⣿⣿⡻⣻⣿⣿⣧⣄⣠⢴⢿⢿⢿⢿⣿⣿⡿⢰⣿⣿⣿
// ⡆⢹⣿⣿⣝⢸⡂⡇⡎⡮⣿⣷⣿⣿⡿⣿⡿⠀⣿⢿⣿⣿⣷⣟⡎⡽⡕⡇⡇⡳⡽⣿⣿⡇⢼⢸⣿⣿⡇⢽⣿⣝⢹⡊⣇⡃⣗⣿⣿⡏⠏⣃⡘⠿⢹⣿⣿⢮⢹⡩⣍⣇⢷⢽⣿⡏⢼⣿⣿⣿
// ⣿⡄⢻⣿⣿⣷⣯⣯⣯⣯⣿⣿⣿⣿⣷⣥⡥⠳⢬⣼⣿⣿⣿⣷⣯⣯⣯⣯⣯⣯⣿⣿⣿⢠⣿⢸⣿⣿⣿⣄⠻⣿⣷⣿⣾⣽⣾⣿⣿⣿⣷⡘⠝⣼⣿⣿⣿⣯⣷⣿⣾⣾⣽⣽⡿⢠⣿⣿⣿⣿
// ⠙⠙⠂⠙⢙⢙⢙⢙⠙⡙⢙⢙⠙⠙⠙⠙⠙⡙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠉⠘⠙⠘⠙⠙⠙⠙⠒⠈⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠋⠃⠙⠙⠙⠙⠙

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>


/**
 * @brief status structure to store all status for watch
 * 
 * ~~~
 * | STATE | CPUID | UTIME  | STIME  | VSIZE  | MINFLT | MAJFLT |
 * |-------|-------|--------|--------|--------|--------|--------|
 * | 3     | 39 %d | 14 %lu | 15 %lu | 23 %lu | 10 %lu | 12 %lu |
 * ~~~
 */
struct status {   
  int cpuid;
  unsigned long utime;
  unsigned long stime;
  unsigned long vsize;
  unsigned long minflt;
  unsigned long majflt;
  char state;
  struct status *nextStatus;
};


int takeInput();
int watch(char **param, int paramno);
int noPipe(char **param, int paramno);
int yesPipe(char **param, int paramno);
void pipeExecute(char **param, int paramno, int pipeCount, int *cmdIndex);
int executeCMD(char **param);
void sigintHandler();
void sigusr1Handler();


int sigint_received = 0;

/**
 * @brief SIGINT handler
 * 
 * @param sig 
 */
void sigintHandler(int sig) {
    sigint_received = 1;
    return;
}

/**
 * @brief SIGUSR1 handler
 * 
 * @param sig 
 */
void sigusr1Handler(int sig) {
    return;
}

/**
 * @brief take & process input
 * 
 * @return 0 only if valid exit
 */
int takeInput() {
    // array for input line
    char input[1025];

    // array for splitted line
    char **param = malloc(sizeof(char *)*31);

    printf("## 3230yash >> ");
    fgets(input, 1024, stdin);
    // restart input reading on Ctrl+c
    if (sigint_received) {
        free(param);
        sigint_received = 0;
        printf("\n");
        return 1;
    }
    
    // TODO: improve split
    // split
    param[0] = strtok(input, " ");

    // number of input parameters
    int paramno = 1;
    while (param[paramno] = strtok(NULL, " ")) {
        paramno++;    
    }
    // to remove the weird NULL or new line character 
    // from strtok for the last parameter.
    *((param[paramno-1])+strlen(param[paramno-1])-1) = '\0';

    // exit condition 
    if (strcmp(param[0], "exit") == 0) {
        if (paramno == 1) {
            free(param);
            return 0;
        }
        printf("3230yash: \"exit\" with other arguments!!!\n");
        free(param);
        return 1;
    }

    // incorrect pipe sequence
    if (strcmp(param[0], "|") == 0 || strcmp(param[paramno-1], "|") == 0) {
        printf("3230yash: Incorrect pipe sequence\n");
        free(param);
        return 1;
    }

    // consecutive pipe
    for (int i = 0; i < paramno - 1; i++) {
        if (strcmp(param[i], "|") == 0 && strcmp(param[i+1], "|") == 0) {
            printf("3230yash: should not have two consecutive | without in-between command\n");
            free(param);
            return 1;
        }
    }

    // watch
    if (strcmp(param[0], "watch") == 0) {
        if (watch(&param[1], paramno) == 2){
            free(param);
            exit(1);
        }
        free(param);
        return 1;
    }

    // execute if no pipe
    if (noPipe(param, paramno)) {
        pid_t pid = fork();
        if (pid == 0) {
            // child response to SIGINT
            signal(SIGINT, SIG_DFL); 
            // execute & terminate itself if error
            if (executeCMD(param)) {
                free(param);
                exit(0);
            }
        }
        else {
            // parent ignore SIGINT
            signal(SIGINT,SIG_IGN);

            int status;
            waitpid(pid, &status, 0);
            if (WIFSIGNALED(status)){
                // getting process name
                char *cmd = param[0];
                char *processName = cmd;
                char *lastSlash = strrchr(cmd, '/'); // Find last '/'
                if (lastSlash != NULL) {
                    processName = lastSlash + 1;
                }
                printf("%s: %s\n", processName, strsignal(WTERMSIG(status)));
            }
            
        }
    }
    // pipe
    else {
        if (yesPipe(param, paramno));
        else printf("Too many pipes bro! At most 4!\n");
    }


    free(param);
    return 1;
}

/**
 * @brief processes piped commands & push to exec
 * 
 * @param param 
 * @param paramno 
 * @return 0 if too many pipes (>4)
 */
int yesPipe(char **param, int paramno) {
    // count pipe
    int pipeCount = 0;
    // index out the location of pipe in param
    int cmdIndex[5];
    cmdIndex[0] = 0;
    for (int i = 0; i < paramno; i++) {
        if (strcmp(param[i], "|") == 0) {
            if (pipeCount < 4) {
                cmdIndex[pipeCount+1] = i+1;
                param[i] = NULL;
            }
            // more than 4 pipes!!!
            else return 0;
            pipeCount++;  
        }
    }
    
    pipeExecute(param, paramno, pipeCount, cmdIndex);

    return 1;
}


/**
 * @brief handling the pipes between child process & fork,
 *         push to exec
 * 
 * @param param 
 * @param paramno 
 * @param pfd 
 * @param pipeCount 
 * @param cmdIndex 
 */
void pipeExecute(char **param, int paramno, int pipeCount, int *cmdIndex) {
    
    // handle pipes
    int pfd[4][2];
    //create pipeCount number of pipes
    for (int i = 0; i < pipeCount; i++) {
        pipe(pfd[i]);
    }

    pid_t children[5];
    for (int i = 0; i < pipeCount + 1; i++) {
        children[i] = fork();
        // child
        if (children[i] == 0) {
            
            for (int j = 0; j < pipeCount; j++) {
                // dup or close read pipes
                if (j == i-1) {
                    dup2(pfd[j][0], 0);
                } else close(pfd[j][0]);
                if (j == i) {
                    dup2(pfd[j][1], 1);
                } else close(pfd[j][1]);
            }
            signal(SIGINT, SIG_DFL);
            if (executeCMD(&param[cmdIndex[i]])) {
                free(param);
                // idk what do when middle one does not exist
                // turns out just exit and it'll be fine, probably
                exit(-1);
            }
        } 
    }

    signal(SIGINT, SIG_IGN);
    for (int i = 0; i < pipeCount; i++) {
        close(pfd[i][0]);
        close(pfd[i][1]);
    }

    // now we have pipeCount + 1 process running. how do we waitpid them
    int status;
    for (int i = 0; i < pipeCount + 1; i++) {
        waitpid(children[i], &status, 0);
        if (WIFSIGNALED(status)){
            // getting process name 
            char *cmd = param[cmdIndex[i]];
            char *processName = cmd;
            char *lastSlash = strrchr(cmd, '/'); // Find last '/'
            if (lastSlash != NULL) {
                processName = lastSlash + 1;
            }
            printf("%s: %s\n", processName, strsignal(WTERMSIG(status)));
        }
    }
    
    return;
}

/**
 * @brief function for implementing watch
 * 
 * @param param array of parameters
 * @param paramno number of parameters
 * @return doesnt really matter
 */
int watch(char **param, int paramno) {
    for (int i = 0; i < paramno-1; i++) {
        if (strcmp(param[i], "|") == 0) {
            printf("3230yash: Cannot watch a pipe sequence\n");
            return 1;
        }
    }
    
    pid_t pid = fork();
    if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        // wait for parent to send signal after getting 
        // initial stat from proc
        signal(SIGUSR1, sigusr1Handler);
        pause();
        if (executeCMD(param)) return 2;
    }
    signal(SIGINT, SIG_IGN);
    // pid will not change hence path is static
    char path[1000];
    sprintf(path, "/proc/%d/stat", pid);
    
    struct status *firstStatus = (struct status *)malloc(sizeof(struct status));
    struct status *currNode = firstStatus;

    char state = '\0';


    //// read before exec
    struct status *new = (struct status *)malloc(sizeof(struct status));
    new->nextStatus = NULL;
    currNode->nextStatus = new;
    FILE *fp = fopen(path, "r");
    // find last ')' 's location relative to the start
    // of the file,
    // avoiding weird stuff going on within comm
    long offset;
    char c;
    while (1) {
        c = fgetc(fp);
        if (c == ')') offset = ftell(fp);
        if (c == EOF) break;
    }
    fseek(fp, offset, 0);
    // start reading 
    fscanf(fp, " %c", &state);
    // skip unused and take input
    for (int i = 4; i <=9; i++) fscanf(fp, " %*u");
    fscanf(fp, " %lu %*u %lu %*u", &(new->minflt), &(new->majflt));
    fscanf(fp, " %lu %lu", &(new->utime), &(new->stime));
    for (int i = 16; i <=22; i++) fscanf(fp, " %*u");
    fscanf(fp, " %lu", &(new->vsize));
    for (int i = 24; i <=38; i++) fscanf(fp, " %*u");
    fscanf(fp, " %d", &(new->cpuid));
    
    fclose(fp);
    new->state = state;
    currNode = currNode->nextStatus;
    ////
    
    // retrieving the old mask fo SIG_BLOCK and 
    // adding sigchld as blocked
    sigset_t mask, oldmask;
    sigprocmask(SIG_BLOCK, NULL, &mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &mask, &oldmask);
    // instruct child to start executing
    kill(pid, SIGUSR1);

    //
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);

    // loop per 500ms unless sigchld
    struct timespec timeout = {0, 500000000};
    while (state != 'Z' && sigtimedwait(&mask, NULL, &timeout) == -1) {
        new = (struct status *)malloc(sizeof(struct status));
        new->nextStatus = NULL;
        currNode->nextStatus = new;
        fp = fopen(path, "r");
        while (1) {
            c = fgetc(fp);
            if (c == ')') offset = ftell(fp);
            if (c == EOF) break;
        }
        fseek(fp, offset, 0);

        // start reading 
        fscanf(fp, " %c", &state);
        // skip unused and take input
        for (int i = 4; i <=9; i++) fscanf(fp, " %*u");
        fscanf(fp, " %lu %*u %lu %*u", &(new->minflt), &(new->majflt));
        fscanf(fp, " %lu %lu", &(new->utime), &(new->stime));
        for (int i = 16; i <=22; i++) fscanf(fp, " %*u");
        fscanf(fp, " %lu", &(new->vsize));
        for (int i = 24; i <=38; i++) fscanf(fp, " %*u");
        fscanf(fp, " %d", &(new->cpuid));

        fclose(fp);
        new->state = state;
        currNode = currNode->nextStatus;
    }
    
    //// read after child becomes is zombie, (wait until it's updated)
    new = (struct status *)malloc(sizeof(struct status));
    new->nextStatus = NULL;
    currNode->nextStatus = new;
    while (1) {
        fp = fopen(path, "r");
        // find last ')' 's location relative to the start
        // of the file,
        // avoiding weird stuff going on within comm
        while (1) {
            c = fgetc(fp);
            if (c == ')') offset = ftell(fp);
            if (c == EOF) break;
        }
        fseek(fp, offset, 0);
        
        // start reading 
        fscanf(fp, " %c", &state);
        
        // make sure it's updated!!!
        if (state != 'Z') {
            fclose(fp);
            continue;
        }

        // skip unused and take input
        for (int i = 4; i <=9; i++) fscanf(fp, " %*u");
        fscanf(fp, " %lu %*u %lu %*u", &(new->minflt), &(new->majflt));
        fscanf(fp, " %lu %lu", &(new->utime), &(new->stime));
        for (int i = 16; i <=22; i++) fscanf(fp, " %*u");
        fscanf(fp, " %lu", &(new->vsize));
        for (int i = 24; i <=38; i++) fscanf(fp, " %*u");
        fscanf(fp, " %d", &(new->cpuid));

        fclose(fp);
        new->state = state;
        currNode = currNode->nextStatus;
        break;
    }
    ////

    // reap the child
    waitpid(-1, NULL, 0);
    // restore old sigblock mask
    sigprocmask(SIG_BLOCK, &oldmask, NULL);
    


    // free the whole list
    currNode = firstStatus->nextStatus;
    struct status *nxtNode;
    printf("\nSTATE CPUID UTIME STIME VSIZE     MINFLT MAJFLT\n");
    while (currNode != NULL) {
        // todo: print it
        printf("%-5c %-5d %-5.2Lf %-5.2Lf %-9lu %-6lu %-6lu\n", 
            currNode->state, currNode->cpuid,
            (long double) currNode->utime / sysconf(_SC_CLK_TCK), 
            (long double) currNode->stime / sysconf(_SC_CLK_TCK), 
            currNode->vsize, currNode->minflt, currNode->majflt);

        // free it
        nxtNode = currNode->nextStatus;
        free(currNode);
        currNode = nxtNode;
    }
    free(firstStatus);

    return 0;
}

/**
 * @brief function to execute commands
 * 
 * @param param parameters to input 
 */
int executeCMD(char **param) {
    // relative path or absolute path
    if (param[0][0] == '.' || param[0][0] == '/') {
        execv(param[0], param);
        // only execute when error
        printf("'%s': %s\n", param[0], strerror(errno));
    }
    // $PATH 
    else {
        execvp(param[0], param);
        // only execute when error
        printf("'%s': %s\n", param[0], strerror(errno));
    }
    // error, no executes
    return 1;
}

/**
 * @brief check pipe exist
 * 
 * @param param 
 * @param paramno 
 * @return 1 if no pipe in input esle 0
 */
int noPipe(char **param, int paramno) {
    for (int i = 0; i < paramno; i++) {
        if (strcmp(param[i], "|") == 0) return 0;
    }
    return 1;
}

/**
 * @brief main
 * 
 */
int main() {
    // presets for SIGINT handler 
    struct sigaction sa;
    sigaction(SIGINT, NULL, &sa);
    sa.sa_handler = sigintHandler;


    while (1) {
        // install signal handler for SIGINT to ignore sigint everytime
        // since SIGINT default interrupts fgets, not change of flags needed
        sigaction(SIGINT, &sa, NULL);
        if (takeInput() == 0) exit(0);
    }
    return 0;
}