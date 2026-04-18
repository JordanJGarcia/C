/*
 * Name: scanf.c
 * Desc:
 *      Demonstrates use of scanf().
 */

#include <stdio.h>

#define MAX 80

int
main(void)
{
    int i1, i2;
    long l;
    double d;
    char buf1[MAX], buf2[MAX];

    puts("Make sure you read the source code!!\n");

    puts("Enter a long integer and a floating point number:");
    scanf("%ld %lf", &l, &d);
    printf("You entered %ld and %lf.\n", l, d);

    fflush(stdin);

    puts("Enter a 5 digit integer (for example, 54321):");
    scanf("%2d%3d", &i1, &i2);
    printf("You entered %d and %d\n", i1, i2);

    fflush(stdin);

    puts("Enter your first and last names separated by a space:");

    // this one is weird to me...
    // by excluding the space character, it causes the input to be split
    scanf("%[^ ]%s", buf1, buf2);
    printf("First name: %s\nLast name: %s\n", buf1, buf2);

    return 0;
}
