/*
Software Systems Spring 2018
tee program copies output to file(s) and standard output

Camille Xue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int append = 0;
    char ch;

    // check flags
    while((ch = getopt(argc, argv, "a")) != EOF) {
        switch(ch) {
            case 'a':
            append = 1;
            break;
        default:
            exit(1);
        }
    }
    argc -= optind;
    argv += optind;

    char line[80]; // line by line buffer
    char input[200]; //entire input

    while(fgets(line, 80, stdin)){
        printf("%s", line); //prints output to stdout
        strcat(input, line);
    }

    //if append flag, don't overwrite file, just add to it
    if (append) {
        for (int i = 1; i < argc; i++) {
            FILE *output_file = fopen(argv[i], "a");
            fprintf(output_file, "%s", input);
            fclose(output_file);
        }
    }
    else {
        for (int i = 1; i < argc; i++) { //iterate through all files
            FILE *output_file = fopen(argv[i], "w");
            fprintf(output_file, "%s", input);
            fclose(output_file);
        }
    }

    return 0;
}

/*
The part that slowed me down most was trying to figure out how to read the
entire standard input if it was multiple lines. One of my biggest problems
initially was that it seemed to only be reading the last input with my test
exampe of ls | ./tee output.txt. and debugging that took time. I still don't
think I fully figured out the best solution, but it seems like it would be
easier if the standard input was just one line at a time. Next time I would try
to find a better solution than the one I came up with.

Compared to mine, the professional implementations seem a lot more thorough in
terms of making sure nothing goes wrong. There are a lot more definitions and
explicit things to make sure nothing goes wrong. The way it handles the files
also seems different than what I did, and some of it seems more complicated than
what I can understand. There's also more clear error messages or exit statuses.




*/
