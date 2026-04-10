# Lesson 3

Storing Information: Variables and Constants

## Notes

### Memory
- A computer uses random-access memory (RAM) to store information while it operates.
- RAM is volatile, which means that it is erased and replaced with new information as often as needed, 
and loses its informatoin when you turn the computer off.
- RAM is organized sequentially, 1 byte following another.
    + Each byte of memory has a unique address that can be used to identify it.
    
### Variables
- A named data storage location in your computer's memory.
- Variable names must adhere to the following rules:
    + Can contain letters (a to z and A to Z), digits (0 to 9), and the underscore characte (\_).
    + The first character cannot be a digit, and underscores are not recommended.
    + Names are case-sensitive.
    + Cannot use keywords.
- Variables must be declared before they can be used.

### Numeric Variables
- Different numeric values have varying memory storage requirements.
- Two main categories:
    + *Integer variables* hold values that have no fractional part.
        * signed (- or +)
        * unsigned (0+)
    + *Floating-point variables* hold values that have a fractional part.
- A `char` is a type of numeric variable, making everything technically a numeric data type.
- Integer variables are signed by default.

### The `typedef` Keyword
- Used to created a new name for an existing data type.
- In effect, it creates a synonym.
- The most common use of `typedef` concerns aggregate data types (structs/unions).

### Declaring/Initializing Variables
- When you **declare** a variable, you instruct the compiler to set aside storage space for the variable.
- The value stored in that space is not defined yet, it might be zero or some 'garbage' value.
- Before using a variable, you must always **initialize** it to a known value.
    + `int count;       // set aside storage space for count`
    + `count = 0;       // store 0 in count`
    + `int count = 0;   // declared and initialized simultaneously`

### Constants
- Like a variable, a *constant* is a data storage location used by your program.
- Unlike a variable, the value stored in a constant can't be changed during program execution.
- C has **2 types of constants**:
    + Literal constants
        - A value that is typed directly into the source code wherever it is needed.
            + `int count = 20` **20** is the literal constant
    + Symbolic constants
        - A constant represented by a name (symbol) in your program.
        - C has 2 methods for defining a symbolic constant:
            + the `#define` directive
            + the `const` keyword
