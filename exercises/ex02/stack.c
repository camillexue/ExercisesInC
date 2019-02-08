/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array; /*warning: function returns address of local variable
    [-Wreturn-local-addr]
    this is a bad idea because the stack gets cleared when function is done, stack frame is deallocated,
    address is now address of unallocated memory */

    /* when I run it, I get a segmentation fault which means that the program
    tried reading or writing to memory it's not allowed to, which makes sense because
    the adress is unallocated memory and it's not allowed to do anything with it.

    Commenting out the print statements in foo and bar gets rid of the seg fault,
    but there is still the warning about how foo returns the address of a local
    variable.

    When I uncomment the print statements in foo and bar, the segmentation fault
    occurs again and the warning happens again. The printed array variable for
    both of them is the same address given */
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
