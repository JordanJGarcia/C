/*
 * Name: array_of_strings.c
 * Desc:
 *      Demonstrates the use of an array of strings.
*/

#include <stdio.h>

#define SIZE 8

void print_strings(char* s[], int n);

int
main(void)
{
    char* msg[SIZE] = { "Four", "score", "and", "seven", "years", "ago,", "our", "forefathers..." };

    print_strings(msg, SIZE);

    return 0;
}


void print_strings(char* s[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s ", s[i]);
    
    printf("\n");

    return;
}
