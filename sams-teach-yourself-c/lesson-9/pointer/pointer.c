/*
 * Name: pointer.c
 * Desc:
 *      Demonstrates basic pointer use.
 */

#include <stdio.h>

int main(void)
{
    int var = 1, *ptr = &var;

    printf("Direct access: var = %d\n", var);
    printf("Indirect access: var = %d\n", *ptr);

    printf("Address of var = %p\n", &var);
    printf("Address of var = %p\n", ptr);

    return 0;
}
