#include <stdio.h>
/*
    In general, with optimization, the assembly code becomes much shorter
    and more concise. It will automatically get rid of unecessary or unused
    variables or replace functions with simpler ones.
*/
int main() {
    int x = 5;
    printf("Hello, World!\n"); //optimizes by changing printf to puts
    // printf("%d\n", x);

    int y = x + 1; //optimizes by doing math first and setting it equal to y
    printf("%d\n", y);

    return 0;
}
