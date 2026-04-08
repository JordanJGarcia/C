# Lesson 5

Packaging Code in Functions

## Notes

* Functions are central to C programming and to the philosophy of C program design (modularity).
* Function
    - A named, independent section of C code that performs a specific task and optionally returns a value to the calling program.
* Function Prototype
    - Provides the compiler with a description of a function that will be defined at a later point in the program.
    - Variable names are optional in prototypes, but their types are required.
    - Always ends with a semicolon.
```
return-type function_name(arg-type name_1, ..., arg-type name_n);
```
* Function Definition
    - Contains the code that will be executed.
    - The first line of the function, called the *function header*, should be identical to its prototype (add arg names if they aren't in prototype).
    - It is good practice to include return statements in all functions, even ones with *void* return types.
```
return-type function_name(arg-type name_1, ..., arg-type name_n)
{
    /* statements */
}
```
* Local Variables
    - Variables declared in a function (within the body block) are called *local variables*
    - This means they are private to that particular function and are distinct from other variables of the same name declared elsewhere in the program.
* Function Statements
    - There is essentially no limitation on the statements that can be included within a function.
    - The only thing you can't do inside a function is *define another function*.
    - Functions should perform simple tasks, and be kept relatively short (<30 lines is a good general rule of thumb).
* Function Arguments
    - Each argument can be any valid C expression: a constant, a variable, a mathematical or logical expression, or even another function (one with a return value).
* Recursive Functions
    - *Recursion* occurs when a function calls itself.
    - *Indirect recursion* occurs when a function calls another function that then calls the first function.
* Inline Functions
    - Generally small functions.
    - When the compiler executes, it ***tries*** to execute an inline function in the fastest manner possible.
        + It is not guarenteed that the compiler will copy the function code into its calling function, that is just the general assumption.
    - A function is made inline by using the *inline* keyword.
```
inline int toInches(int feet)
{
    return (feet*12);
}
```
