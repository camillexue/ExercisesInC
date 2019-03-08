/*
this program allows the user to enter integers, one per line, until the user
hits Control-D, then it prints the sum of all the integers

Camille Xue
February 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
collect_numbers: gets input from user and stores integers in array
user inputs a number per line ends input with Ctrl-D.

numbers: gets pointer to numbers array, stores the converted string input to int
input: buffer for string input

*/
int collect_numbers(int* numbers) {
    int done = 0;
    char input[11]; // buffer
    int i = 0; //index for numbers[i]

    printf("Enter 10 numbers each separated by lines. Ctrl-D to sum.\n");

    while(!done) {

        if (scanf("%10s", input) == EOF) {
            printf("Done collecting input.\n");
            done = 1;
            return -1;
        }
        //if something other than a number is entered, return error message
        else if (atoi(input) == 0 && strcmp(input, "0\0") != 0) {
            printf("That's not a valid input.\n");
            done = 1;
            return -2;
        }
        else if (i > 10) {
            printf("The input has exceeded the buffer size. ");
            printf("Ctrl-D to enter input.\n");
            done = 1;
            return -3;
        }
        else {
            numbers[i] = atoi(input);
            //printf("%d\n", numbers[i]);
            i++;
        }
    }
    //if user enters less than 10 numbers, set rest to 0
    if (i < 10) {
        for(int x = i; x < 10; x++) {
            numbers[x] = 0;
        }
    }
    return 0;
}

/*
sum: adds up the total of all the integers in an array, returns total

numbers: integer array
length: number of elements in the array
total: total sum of elements
*/
int sum(int* numbers, int length) {
    int total = 0;
    for(int i = 0; i < length; i++) {
        //printf("%d\n", numbers[i]);
        total = total + numbers[i];
    }
    printf("%d\n", total);
    return total;
}

int main() {
    int numbers[10];
    printf("status: %d\n", collect_numbers(numbers));
    sum(numbers, 10);
    return 0;
}
