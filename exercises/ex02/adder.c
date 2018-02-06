/*
this program allows the user to enter integers, one per line, until the user
hits Control-D, then it prints the sum of all the integers

Camille Xue
February 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void collect_numbers(int* numbers) {
    int done = 0;
    char input[11];
    int i = 0; //index for numbers[i]

    printf("Enter 10 numbers each separated by lines. Ctrl-D to sum.\n");

    while(!done) {

        if (scanf("%10s", input) == EOF) {
            printf("Done collecting input.\n");
            done = 1;
        }
        else if (atoi(input) == 0 && strcmp(input, "0\0") != 0) {
            printf("That's not a valid input.\n");
            done = 1;
        }
        else if (i > 10) {
            printf("The input has exceeded the buffer size. ");
            printf("Ctrl-D to enter input.\n");
            done = 1;
        }
        else {
            numbers[i] = atoi(input);
            //printf("%d\n", numbers[i]);
            i++;
        }
    }
    if (i < 10) {
        for(int x = i; x < 10; x++) {
            numbers[x] = 0;
        }
    }
}

int sum(int* numbers) {
    int total = 0;
    for(int i = 0; i < 10; i++) {
        //printf("%d\n", numbers[i]);
        total = total + numbers[i];
    }
    printf("%d\n", total);
    return total;
}

int main() {
    int numbers[10];
    collect_numbers(numbers);
    sum(numbers);
    return 0;
}
