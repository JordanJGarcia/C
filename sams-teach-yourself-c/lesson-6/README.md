# Lesson 6

Basic Program Control

## Notes

* Arrays
    - An *array* is an indexed group of data storage locations that have the same name and are distinguished from each other by a *subscript*, or *index*

* Controlling Program Execution
    - *if* statement
    - *for* statement
    - *while* statement
    - *do...while* statement

```
for (initial; condition; increment)
    statement;
```
* For Statement
    - *initial*, *condition*, and *increment* are all C expressions.
    - You can omit *initial* if the test variable has been initialized previously in your program.
    - *initial* doesn't need to be an actual initialization, it can be any valid C expression.
    - You can also omit *increment*, doing that in the body of the for statement instead.
    - Semicolon's must still be included if you omit either of these.
    - What happens:
        + 1 - *initial* is evaluated, it is usually an assignment statement.
        + 2 - *condition* is evaluated
            - if **false**, the for statement terminates and execution is passed to the first statement following it.
            - if **true**, the C statements in the for loop are executed.
        + 3 - *increment* is evaluated
        + 4 - Execution returns to step 2.

```
while (condition)
    statement;
```
* While Statement
    - Executes a block of statements as long as *condition* evaluates to true (nonzero).
    - If *condition* evaluates to false on first loop, the statement(s) in the body are never run.
    - *condition* is any C expression.
    - What happens:
        + 1 - *condition* is evaluated.
            - If **false**, the while statement terminates and execution is passed to the first statement following it.
            - If **true**, the C statement(s) in the body of the while statement are executed.
        + 2 - Execution returns to step 1. 

```
do
    statement
while (condition);
```
* Do...While Statement
    - Executes a block of statements as long as a specified condition is true.
    - The statement(s) in the body are always run at least once.
    - `for` statements and `while` statements test *condition* at the beginning, whereas `do...while` tests *condition* at the end.
    - What happens:
        + 1 - The statements in *statement* are executed.
        + 2 - *condition* is evaluated.
            - If **true**, execution returns to step 1.
            - If **false**, the loop terminates.

