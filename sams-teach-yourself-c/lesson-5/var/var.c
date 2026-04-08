/*
 * Name: var.c
 * Desc:
 *      Demonstrate local variables.
 */

#include <stdio.h>

int x = 1, y = 2;

void demo(void);

int main(void)
{
    printf("Before calling demo(),\tx=%d\ty=%d\n", x, y);
    demo();
    printf("After calling demo(),\tx=%d\ty=%d\n", x, y);

    return 0;
}

void demo(void)
{
    int x = 88, y = 99;
    printf("Within demo(),\t\tx=%d\ty=%d\n", x, y);
    return;
}
