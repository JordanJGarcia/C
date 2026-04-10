/*
 * Name: arrays.c
 * Desc:
 *      Demonstrates use of single-dimensional arrays.
 */

#include <stdio.h>

#define MONTHS 12

int main(void)
{
    float expenses[MONTHS], total = 0;
    int i = 0;

    for (i = 0; i < MONTHS; i++)
    {
        printf("Enter expenses for month %d: ", i + 1);
        scanf("%f", &expenses[i]);
        total += expenses[i];
    }
    printf("Yearly expenses are $%.2f\n", total);

    return 0;
}
