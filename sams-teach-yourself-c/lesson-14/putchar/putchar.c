/*
 * Name: putchar.c
 * Desc:
 *      Demonstrates use of putchar().
 */

#include <stdio.h>
#include <string.h>

#define MAX 80

int
main(void)
{
    char msg[] = "Displayed with putchar().";

    for (int i = 14; i < 128; i++)
        putchar(i);

    putchar('\n');

    for (int i = 0; i < strlen(msg); i++)
        putchar(msg[i]);

    putchar('\n');

    return 0;
}
