/*
 * Name: arraysize.c
 * Desc:
 *      Demonstrates the relationship between addresses and
 *      elements of arrays of different data types
 */

#include <stdio.h>

int main(void)
{
    int ctr;
    short array_s[10];
    float array_f[10];
    double array_d[10];

    printf("\t\tShort\t\t\tFloat\t\t\tDouble\n");
    printf("=======================================");
    printf("=======================================\n");

    for (ctr = 0; ctr < 10; ctr++)
        printf("Element %d:\t%p\t\t%p\t\t%p\n", ctr, &array_s[ctr], &array_f[ctr], &array_d[ctr]);

    printf("=======================================");
    printf("=======================================\n");

    return 0;
}
