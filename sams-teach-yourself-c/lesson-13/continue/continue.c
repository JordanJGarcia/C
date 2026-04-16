/*
 * Name: continue.c
 * Desc:
 *      Demonstrates use of continue statment.
 *      Also thought it was kinda cool the way it skips vowels.
 */

#include <stdio.h>

int
main(void)
{
    char buffer[81];
    
    puts("Enter a line of text (80 chars max):");
    fgets(buffer, sizeof(buffer), stdin);


    for (char* c = buffer; *c != '\0'; c++)
    {
        if (*c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u')
            continue;

        putchar(*c);
    }

    return 0;
}
