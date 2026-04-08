/*
 * Name: cube.c
 * Desc:
 *      Demonstrates a simple function.
 */

#include <stdio.h>

/* prototype */
long long cube(long x);

int main(void)
{
    long value;

    printf("Enter an integer value: ");
    scanf("%ld", &value);
    printf("The cube of %ld is %lld\n", value, cube(value));

    return 0;
}

long long cube(long x)
{
    return x * x * x;
}
