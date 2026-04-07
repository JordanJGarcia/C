# Lesson 4

The Pieces of a C Program: Statements, Expressions, and Operators

## Notes

* Statements
    - A complete instruction that directs the computer to carry out some task.
    - In C, statements are typically written one per line, but can expand multiple lines, and always end with a semicolon (except for preprocessor directives).
    - White space does not matter, *except for within literal string constants*.

* Null Statements
    - If you place a semicolon by itself on a line, you create a *null statement*
        + `;`

* Compound Statements (Blocks)
    - A *compound statement*, also called a *block*, is a group of two or more C statements enclosed in braces.
    - In C, a block can be used anywhere a single statement can be used.
```
{
    printf("Hello, ");
    printf("world!");
}
```


* Expressions
    - In C, an *expression* is anything that evaluates to a numeric value.

* True/False values
    - A value of zero represents false.
    - Any nonzero value represents true.

* Operators
    - An *operator* is a symbol that instructs C to perform some operation, or action, on one or more operands.
    - An *operand* is something that an operator acts on, in C all operands are expressions.
    - C operators fall into several categories:
        + Assignment operator
        + Mathematical operators
        + Relational operators
        + Logical operators

* Mathematical Operators
    - Operator Precedence:
        + `()` Always first, without regard to operator precedence.
        + 1 `++ --`
        + 2 `* / %`
        + 3 `+ -`

* Relational Operators
    - An expression containing a relational operator evalutes to either *true (1)* or *false (0)*
    - Operators:
        + `>`
        + `<`
        + `>=`
        + `<=`
        + `==`
        + `!=`
    - All relational operators have a lower precedence than the mathematical operators.
    - Operator precedence:
        + `()` Always first, without regard to operator precedence.
        + 1 `< <= > >=`
        + 2 `!= ==`

* Logical Operators
    - C's logical operators let you combine two or more relational expressions into a single expression that evaluates to either *true (1)* or *false (0)*.
    - Operators:
        + `&&`
        + `||`
        + `!`
    - Operator precedence:
        + `!` has precedence equal to `++ --`, thus has a higher precedence than all relational operators and all binary mathematical operators.
        + `&& ||` have much lower precedence, lower than all the mathematical and relational operators. `&&` has higher precedence than `||`.
        + As with all C operators, you can use `()` to force precedence.

* Compound Assignment Operators
    - C's *compound assignment operators* provide a shorthand methnod for combining a binary mathematical operation with an assignment operation.
    - Operators:
        + `+=`
        + `-=`
        + `/=`
        + `*=`
        + `%=`

* Conditional Operator (Ternary Operator)
    - The conditional operator is C's only *ternary* operator, meaning that it takes 3 operands.
    - Syntax:
        + `exp1 ? exp2 : exp3;`

* Comma Operator
    - The comma operator is frequently used in C as a simple punctuation mark, serving to separate variable declarations, function arguments, and so on.
    - In certain situations, the comma acts as an operator rather than just as a separator.
    - You can form an expression by separating two subexpressions with a comma; the result is as follows:
        + Both expressions are evaluated, with the left expression being evaluated first.
        + The entire expressiond evaluates to the value of the right expression.
            - `x = (a++, b++);` Assigns the value of b to x, then increments a, and then increments b.
            - Paretheses are necessary because the comma operator has low precedence, even lower than the assignment operator.
    - It is most commonly used in for loops.


* Precedence of ALL C operators

1. `() [] -> .`
2. `! ~ ++ -- * (indirection) & (address of) (type)`
3. `sizeof + (unary) - (unary)`
4. `+ -`
5. `<< >>`
6. `< <= > >=`
7. `== !=`
8. `& (bitwise AND)`
9. `^`
10. `|`
11. `&&`
12. `||`
13. `?:`
14. `= += -= *= /= %= ^= |= <<= >>=`
15. `,`
