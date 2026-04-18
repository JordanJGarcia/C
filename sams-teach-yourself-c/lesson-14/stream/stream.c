/*
 * Name: stream.c
 * Desc:
 *      Demonstrates the equivalence of stream input and output.
 */

#include <stdio.h>

int
main(void)
{
    char buffer[256];

    /* input a line, then immediately output it. */
    puts(fgets(buffer, sizeof(buffer) - 1, stdin));

    return 0;
}
