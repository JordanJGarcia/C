# Lesson 13

Advanced Program Control

## Notes

### Ending Loops Early
#### The `break` Statement
```
break;
```
* Execution immediately exits the loop.
* Execution is passed to the next statement after the loop.
* When inside a nested loop, it causes the program to exit the *innermost* loop only.

#### The `continue` Statement
```
continue;
```
* The next iteration of the enclosing loop begins immediately.
* Statements between `continue;` and end of enclosing loop are not executed.

### The `goto` Statement
```
goto target;
```
* One of C's *unconditional jump*, or *branching*, statements.
* Execution immediately jumps, or branches, to the location specified by the `goto` statement.
* The target is identified by a text label followed by a colon at the start of a line.
    - Can be on a line by itself or at teh beginning of a line that contains a C statement.
* The `goto` statement and its target *must* be in the same function.
    - They can be in different blocks.

### Infinite Loops
```
while (1)
{
    /* some code */
}
```
```
for (;;)
{
    /* some code */
}
```
```
do
{
    /* some code */
} while (1);
```
* Without the `break` statement, the infinite loop would be useless.
* In general, you should try to avoid infinite loops if there are other alternatives.


### The `switch` Statement
```
switch (expression)
{
    case template_1: statement(s);
    case template_2: statement(s);
    ...
    case template_n: statement(s);
    default: statement(s);
}
```
* *expression* is any expression that evaluates to an integer value (type long, int, or char).
    - This means that the templates must be an integer or char. `case 1: or case 'a':`
* Evaluates *expression* and compares the value against the templates following each `case` label.
* Then one of the following happens:
    - If a match is found between *expression* and one of the templates, execution is transferred to the statement that follows the `case` label.
        - If no `break` statement is included at the end of the `case` label statements, execution will continue on through the remaining labels until it encounters a `break` or just finishes the `switch` statement.
    - If no match is found, execution is transferred to the statement following the optional `default` label.
    - If no match is found and no `default` label exists, execution passes to the first statement following the `switch` statement's closing brace.

### Exiting the Program
* C programs normally exit when it reaches the closing brace of the `main()` function.
* You can terminate the program any time by calling the library function `exit()`.

#### The `exit()` Function
```
#include <stdlib.h>

/* these symbolic constants are defined in <stdlib.h> */
// #define EXIT_SUCCESS 0
// #define EXIT_FAILURE 1

exit(status);
```
* Terminates program execution and returns control to the operating system.
* Takes a single type `int` argument that is passed back to the operating system to indicate the program's success or failure.
    - `0` means the program terminated normally.
    - `1` means the program terminated with some sort of error.
