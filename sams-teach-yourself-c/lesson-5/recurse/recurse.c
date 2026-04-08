/*
 * Name: recurse.c
 * Desc:
 *      Demonstrate function recursion. Calculate the factorial of a number.
 */

#include <stdio.h>

/* prototypes */
unsigned int factorial(unsigned int a);

int main(void)
{
    unsigned int x;

    do {
        puts("Enter an integer value between 1 and 8: ");
        scanf("%d", &x);
    } while (x < 1 || x > 8);

    printf("%u factorial equals %u\n", x, factorial(x));

    return 0;
}

unsigned int factorial(unsigned int a)
{
    if (a == 1)
        return 1;

    return (a *= factorial(a - 1));
}
