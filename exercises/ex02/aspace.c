/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int foo() {
    int var3;
    printf("Address of var 3 is %p\n", &var3);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *r = malloc(128);

    void *r = malloc(10);
    void *r = malloc(10);

    char *s = "Literal string";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p);
    printf ("Address of r is %p\n", r);
    printf ("Address of s is %p\n", s);

    return 0;
}
