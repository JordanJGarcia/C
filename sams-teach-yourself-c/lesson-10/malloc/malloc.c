/*
 * Name: malloc.c
 * Desc:
 *      Demonstrates the use of malloc().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* str;

    // allocate 100 bytes of memory
    if (NULL == (str = (char*) malloc(100)))
    {
        printf("Could not allocate memory\n");
        exit(1);
    }

    printf("String was allocated!\n");

    strcpy(str, "Hello, world!");
    printf("str: %s\n", str);
    free(str);

    return 0;
}
