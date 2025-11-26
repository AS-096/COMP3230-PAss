# COMP3230-PAss

Programming Assignments in COMP3230.

> *For reference only

## Programming assignment 1 - 3230yash

### What's involved
1. `fork()` - to clone current programme
2. `execl, execlp, execle, execv(), execvp(), execvpe()` - to execute specific program
3. `wait(), waitpid(), waitid()` - wait for SIGCHLD and release (or not to release) the zombie process
4. `sigtimedwait()` - suspend process for defined time to wait for defined signal
5. `pipe()` - creates pipe
6. `dup2()` - set pipe ends to read/write
7. `close()` - close unused pipes
8. `signal(), sigaction()` - set signal handlers

### Compiling
In Linux (WSL/Docker) run  
```
gcc 3230yash.c -o 3230yash
```

### Running
```
./3230yash
```

### Functions
`./<path>` - execute with relative path
`/<full path>` - execute with full path
`<$PATH>` - execute with PATH variable
`<program> | <program>` - pipe, up to 4 pipes supported
`watch` - function to monitor execution of process and report use of resources (pipe not supported)
`exit` - exit YASH (SIGINT/^C will not work)

### Known issue
Inputting invalid path in `watch` function may affect following use of `watch` in workbench2. (works fine on WSL) You may want to exit the YASH and run again.

## Programming assignement 2 - jacobi_sema