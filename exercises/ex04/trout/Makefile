main.o: trout.c util.c main.c
	gcc -g -Wall -c main.c
trout.o: trout.h trout.c util.c
	gcc -g -Wall -c trout.c
util.o: util.h util.c
	gcc -g -Wall -c util.c

trout: util.o trout.o main.o
	gcc -g -Wall -o trout util.o trout.o main.o
