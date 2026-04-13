/*
 * Name: arraypass.c
 * Desc:
 *      Demonstrate passing arrays to functions.
 */

#include <stdio.h>

#define MAX 10

int largest(int array[], int size);

int main(void)
{
    int array[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("Enter an integer value: ");
        scanf("%d", &array[i]);
    }

    printf("Largest value = %d\n", largest(array, MAX));

    return 0;
}

int largest(int array[], int size)
{
    int result = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] > result)
            result = array[i];
    }

    return result;
}
