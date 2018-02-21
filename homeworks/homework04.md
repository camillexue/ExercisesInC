## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

They provide a mapping from a file's name to its contents and each file is a sequence of bytes. Files are byte-based but persistent storage is block-based, which means the OS has to trasnlate the byte-based file operations into block-based ones.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The OpenFileTableEntry stores the file position, and it might also store similar information such as the file's status (read, write, etc).

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Operating sustesm have features such as block transfers, prefetching, buffering, and caching to help deal with the relatively slow performance of persistent storage.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

It might have not actually been written to the disk if it was still being stored in memory and was intended to be written to the disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

Since inodes aren't necessarily big enough, they have pointers to indirection blocks which point to other blocks but FAT just contains one entry for each block instead of having indirection blocks. Each FAT entry points to the next cluster. This might be simpler than keeping track of double or triple indirection blocks.

6) What is overhead?  What is fragmentation?

Minimal overhead means that the data structures used by the allocator are small, which maximizes the space avaialable for data. Fragmentation is the unused space the is left and not being used. 

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It is good idea for inter-process communication, where outputs and inputs are treated like files so library functions used for files can also be used for this inter-process communication. It might be a bad idea if the abstraction breaks down and can't be applied, but a programmer still tries to treat something like a file. 

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



