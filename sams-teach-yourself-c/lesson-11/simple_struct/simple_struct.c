/*
 * Name: simple_struct.c
 * Desc:
 *      Demonstrates use of simple structures.
 */

#include <stdio.h>

int
main(void)
{
    struct coord {
        int x;
        int y;
    } point;

    point.x = 12;
    point.y = 14;

    printf("The coordinates are: (%d, %d)\n", point.x, point.y);

    return 0;
}
