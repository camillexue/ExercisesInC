## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/camillexue/ExercisesInC/tree/master/exercises/ex01)


### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages support dynamic types while compiled languages usually only support static types.

2) Name two advantages of static typing over dynamic typing.

Static types save space because the variable names are not stored in memory like dynamic types are. Languages that use static types instead of dynamic types can run faster because it doesn't need to perform extra checks for errors at runtime.

3) Give an example of a static semantic error.

int x = 'c'; would give a static semantic error because the variable value isn't the right type.

4) What are two reasons you might want to turn off code optimization?

When you're first writing your program and have to do a lot of debugging, it's easier to find the problem and keep track of everything without optimization. You also want to make sure that it works normally first, without any optimization before you start making it better.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Gcc is configured to generate the appropriate code for the machine you are running it on, so the results will look different on different computers. If your computer has different architecture it might not generate x86 assembly language like it does for other processors.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

The error might occur at different steps in the compilation process because each stage handles errors differently. The preprocessor will present errors differently than the linker will.

7) What is a segmentation fault?

A segmentation fault occurs when you try to read or write an incorrect location in memory.
