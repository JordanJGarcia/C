/*
 * Name: parith.c
 * Desc:
 *      Demonstrates pointer arithmetic.
 */

#include <stdio.h>

#define MAX 10

int main(void)
{
    int arr[MAX] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, *ptr_to_arr = arr, ctr = 0;

    for (; ctr < MAX; ctr++)
        printf("%d\n", *ptr_to_arr++);

    return 0;
}
