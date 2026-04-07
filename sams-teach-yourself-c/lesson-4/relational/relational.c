/*
 * Name: relational.c
 * Desc:
 *      Demonstrates the evaluation of relational expressions.
*/

#include <stdio.h>

int main(void)
{
    int a = (5 == 5); // evaluates to 1
    printf("a = (5 == 5) = %d", a);

    a = (5 != 5); // evaluates to 0
    printf("\na = (5 != 5) = %d", a);

    a = (12 == 12) + (5 != 1); // evaluates to 1 + 1
    printf("\na = (12 == 12) + (5 != 1) = %d", a);

    return 0;
}
