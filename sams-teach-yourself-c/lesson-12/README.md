# Lesson 12

Understanding Variable Scope

## Notes

### What Is Scope?
* The *scope* of a variable refers to the extent to which different parts of a program have access to the variable.
    - In other words, where the variable is *visible*
* Affects a variables *lifetime*: how long it persists in memory

### External Variables
* An *external variable* is a variable defined outside of any function.
    - This means outside of `main()` as well.
    - Sometimes referred to as *global variables*
* If not explicitly intialized, the compiler automatically initializes it to 0.
* Scope is the entire source code file that contains the variable definition.
* You should use them ***rarely***.
    - Using them violates the principle of *modular independence* that is central to structured programming.
    - ***Modular Independence*** is the idea that each function, or module, in a program contains all the code and data it needs to do its job.
    - Only use external variables when all or most of the program need to access it.
        - Symbolic constants, defined with `const` keyword, are often good candidates.

#### The `extern` Keyword
```
extern type name;
```
* When a function uses an external variable, it is good programming practice to declare the variable within the function using the `extern` keyword.

### Creating Local Variables
* A *local variable* is one that is defined within a function.
* Scope is limited to the function in which it is defined.
* ***Not*** automatically initialized to 0 by the compiler.
    - If not explicitly intialized, it has an undefined or *garbage* value.

#### Static Vs. Automatic Variables
* Local variables are *automatic* by default.
    - This means they are created anew each time the function is called, and destroyed when execution leaves the function.
    - i.e. They don't retain their value between calls to the function in which it is defined.
* For a local variable to retain its value between calls, it must be defined as *static*
```
static type name;
```

### The Scope of Function Parameters
* A variable contained within a function heading's parameter list has *local scope*.
* Because parameter variables always start with the value passed in, it's meaningless to think of them either static or automatic.

### External Static Variables
```
static float rate;

int
main(void)
{
    /* additional code */
}
```
* You can make an external variable static by including the `static` keyword in its definition
* An ordinary external variable is visible to all functions in the file and can be used by functions in other files, as well as any point below its definition.
* A static external variable is visible only to functions in its own file and below the point of definition.

#### Register Variables
* The *register* keyword is used to suggest to the compiler that an automatic local variable be stored in a *processor register* rather than in regular memory.
* Note that you *ask*, not *tell*. It is a ***suggestion***.
    - Depending on the program's needs, a register may not be available.
* Can only be used with simple numeric variables, not arrays or structures.
* Also cannot be used with either static or external storage classes.
* You cannot define a pointer to a register variable (its not in memory).
* Compilers from the last couple decades tend to optimize your code for you in a way that makes the `register` keyword largely unnecessary.

### Local Variables and `main()`
* `main()` is a function just like any other.
* Local variables in main are created when the program begins and their lifetime is over when the program ends.
    - The notion of a static local variable in `main()` therefore does not make sense.
    - The variable cannot retain its value between program executions.
* Within `main()` there is no difference between automatic and static local variables.

### Which Storage Class Should You Use?
* Use automatic storage class whenever possible and use other classes only when needed.

    Storage Class | Keyword | Lifetime | Where It's Defined | Scope
    :------------:|:-------:|----------|--------------------|------
    Automatic | None | Temporary | In a function | Local
    Static | `static` | Temporary | In a function | Local
    Register | `register` | Temporary | In a function | Local
    External | None | Permanent | Outside a function | Global (all files)
    External | `static` | Permanent | Outside a function | Global (one file)


### Local Variables and Blocks
* Variables can be local to blocks just as they are local to functions.
```
int
main(void)
{
    int i = 0;          // local to main
    printf("%d\n", i);  // prints 0

    {
        int i = 999;        // local to the block
        printf("%d\n", i);  // prints 999
    }

    return 0;
}
```
