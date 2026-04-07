# Lesson 2

The Components of a C program

## Notes

* The *only component required* in every C program is the `main()` function.
    - Under normal circumstances, program execution starts at the first statement in `main()` and ends at the last statement in `main()`
    - Per the ANSI standard, the only statement you need to include is the `return` statement.

* Directives:
    - `#include` instructs the C compiler to add the contents of an include file into your program during compilation.
    - `#define` instructs the C compiler to replace a specific term with its assigned value throughout your program.

* Variables:
    - A name assigned to a location in memory used to store information.

* Function Prototypes:
    - Provides the C compiler with the name and arguments of the functions contained in the program.

* Program statements:
    - Do all kinds of things.
    - Generally written one per line and always end with a semicolon.

* Function definition:
    - Contains the actual statements that make up the function.

* Comments:
    - `/* multi-line or single-line comment */`
    - `// single line comment`
    - Don't nest them.

* Blocks:
    - A group of one or more statements enclosed within braces `{}`.
    - You use braces `{}` to enclose the program lines that make up every C function - including the `main()` function.
