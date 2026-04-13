/*
 * Name: charset.c
 * Desc:
 *      Print the ASCII characters and their numeric values.
 */

#include <stdio.h>

#define MAX 256

int main(void)
{
    for (int i = 0; i < MAX; i++)
        printf("character: %c\tnumber: %d\n", (unsigned char)i, i);

    return 0;
}
