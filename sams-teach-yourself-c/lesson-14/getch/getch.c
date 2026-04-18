/*
 * Name: getch.c
 * Desc:
 *      Demonstrates use of getch().
 *      Non-ANSI code.
 *
 *      Unfortunately this does not compile on Ubuntu 24.04 using gcc. I don't think the function is here.
 */

#include <stdio.h>

int
main(void)
{
    int c;

    while ((c = getch()) != '\r')
        putchar(c);

    return 0;
}
