/* 
 * Name: fgets.c
 * Desc:
 *      Demonstrate fgets().
 */

#include <stdio.h>

#define MAX 10

int
main(void)
{
    char buffer[MAX];

    puts("Enter text a line at a time; enter blank to exit.");

    while (1)
    {
        fgets(buffer, MAX, stdin);

        if (buffer[0] == '\n')
            break;

        puts(buffer);
    }

    return 0;
}
