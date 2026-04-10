/*
 * Name: random.c
 * Desc:
 *      Demonstrates random 3 dimensional array.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void)
{
    int rarr[SIZE][SIZE][SIZE];
    int a, b, c;

    /* create random array */
    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            for (c = 0; c < SIZE; c++)
                rarr[a][b][c] = rand();
        }
    }

    /* display array in pager-like fashion */
    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            for (c = 0; c < SIZE; c++)
                printf("\nrarr[%d][%d][%d] = %d", a, b, c, rarr[a][b][c]);

            printf("\nPress Enter to continue, CTRL-C to quit.");
            getchar();
        }
    }

    return 0;
}
