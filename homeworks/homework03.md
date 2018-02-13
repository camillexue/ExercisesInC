## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/camillexue/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

Six bits are needed because it would allow you to store 64 different values. Five bits would only get you 32.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

4294967296 different characters can be represented.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Memory is volatile, but storage is not. When you turn off your computer, the memory is lost but the storage isn't. Storage is also stored on a HDD or SSD.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is 2^30 and GB is 10^9 bytes. The percentage difference is about 7%.

5) How does the virtual memory system help isolate processes from each other?

It helps isolate them because processes cannot access their own addresses of their physical memory, which means they also cannot interfere with the physical memory of other processes. It also ensures that each process has it's own memory that is distinct from other processess (unless it's convenient to share).

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

As they grow and need to add more, they grow towards each other, filling in the gap between them. Having them at opposite ends allows for a big gap between them.

7) What Python data structure would you use to represent a sparse array?

I would use a python dictionary to represent a sparse array.

8) What is a context switch?

It's a mechanism through whichan operating system can interrupt a running process, save its state, and run another process.
