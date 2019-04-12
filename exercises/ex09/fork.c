/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

int global = 5;

// errno is an external global variable that contains
// error information
extern int errno;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    int child_var;
    void *c = malloc(128);

    sleep(i);
    printf("Hello from child %d.\n", i);
    printf("Address of child_var is %p\n", &child_var);
    printf("Address of c is %p\n", &c);
    printf("Address of global is %p\n", &global);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");
    int parent_var;
    void *p = malloc(128);
    printf("Address of parent_var is %p\n", &parent_var);
    printf("Address of p is %p\n", &p);
    printf("Address of global is %p\n", &global);

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}

// Child and parent seem to share the same global, heap, and stack segments
//
// Creating child 0.
// Hello from the parent.
// Address of parent_var is 0x7ffd9f5a7c40 parent stack
// Address of p is          0x7ffd9f5a7c50
// Address of global is     0x56018c2a2010
// Hello from child 0.
// Address of child_var is  0x7ffd9f5a7bfc child stack
// Address of c is          0x7ffd9f5a7c00
// Address of global is     0x56018c2a2010
// Child 30263 exited with error code 0.
// Elapsed time = 0.000318 seconds.

// child_var and parent_var should be on the stack and they have
// addresses that are far apart so they do not share the same stack.
// SHARED: p and c should be allocated on heap and they have close addresses.
// They share the same global as well since the global variable they
// reference is the same, same address
