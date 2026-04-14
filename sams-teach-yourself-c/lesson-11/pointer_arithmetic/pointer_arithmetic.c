/* 
 * Name: pointer_arithmetic.c
 * Desc:
 *      Demonstrate pointer arithemtic with pointers to structures.
 */

#include <stdio.h>

#define MAX 4

int
main(void)
{
    struct part {
        short number;
        char name[12];
    } data[MAX] = {
        { 1, "Part 1" },
        { 2, "Part 2" },
        { 3, "Part 3" },
        { 4, "Part 4" }
    };

    struct part* ptr = data;

    for (int i = 0; i < MAX; i++, ptr++)
        printf("At address %p: %d %s\n", ptr, ptr->number, ptr->name);

    return 0;
}
