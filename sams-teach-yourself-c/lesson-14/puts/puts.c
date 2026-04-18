/*
 * Name: puts.c
 * Desc:
 *      Demonstrates use of puts().
*/

#include <stdio.h>

#define SIZE 5

int
main(void)
{
    char * msgs[SIZE] = { "This", "is", "a", "short", "message." };

    for (int i = 0; i < SIZE; i++)
        puts(msgs[i]);

    puts("what if I pass puts() a not-first character in a string?");
    char * s = "ABCDEFGHIJKLMNOP";
    printf("s = %s\n", s);
    printf("puts(s + 10) = ");
    puts(s + 10);

    return 0;
}
