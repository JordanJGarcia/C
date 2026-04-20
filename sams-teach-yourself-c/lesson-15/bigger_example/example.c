/*
 * Name: example.c
 * Desc:
 *      Tying together multiple topics covered in the book so far.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

int     get_lines(char* lines[]);
void    sort(char* s[], int n);
void    print(char* s[], int n);

int
main(void)
{
    int size;
    char* lines[MAX];
    
    if ((size = get_lines(lines)) < 0)
    {
        fprintf(stderr, "memory allocation error.\n");
        exit(-1);
    }

    sort(lines, size);
    print(lines, size);

    return 0;
}

int
get_lines(char* lines[])
{
    int n = 0;
    char buffer[80]; // temp storage for each line

    puts("Enter one line at a time; enter a blank line when done.");

    // this doesn't work!!
    while ((n < MAX) && (fgets(buffer, sizeof(buffer), stdin) != 0) && (buffer[0] != '\n'))
    {
        if (NULL == (lines[n] = (char*)malloc(strlen(buffer) + 1)))
            return -1;

        strcpy(lines[n++], buffer);
    }

    return n;
}

void
sort(char* s[], int n)
{
    int a, b;
    char* tmp;

    for (a = 1; a < n; a++)
    {
        for (b = 0; b < n - 1; b++)
        {
            if (strcmp(s[b], s[b + 1]) > 0)
            {
                tmp = s[b];
                s[b] = s[b + 1];
                s[b + 1] = tmp;
            }
        }
    }
}

void
print(char* s[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n", s[i]);
}
