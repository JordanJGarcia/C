/*
 * Name: loops.c
 * Desc:
 *      Demonstrates the various C loop statements.
 */

#include <stdio.h>

#define LIMIT 10

int main(void)
{
    int i;

    for(i = 0; i < LIMIT; i++)
        printf("%d\n", i);

    i = 0;
    while(i < LIMIT)
        printf("%d\n", i++);

    i = 0;
    do
        printf("%d\n", i++);
    while(i < LIMIT);

    return 0;
}
