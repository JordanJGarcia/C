/*
 * Name: ptr_sort.c
 * Desc:
 *      Demonstrates practical use of pointers to functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* symbolic constants */
#define MAX 25

/* function prototypes */
int     get_lines(char* lines[]);
void    sort(char* s[], int size, int type);
void    print(char* s[], int size);
int     alpha(char* s1, char* s2);
int     reverse(char* s1, char* s2);

/* main */
int
main(void)
{
    char*   lines[MAX];
    int     num_lines, sort_type;

    num_lines = get_lines(lines);

    if (num_lines < 0)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter 0 for reverse order sort, 1 for alphabetical:");
    scanf("%d", &sort_type);

    sort(lines, num_lines, sort_type);
    print(lines, num_lines);

    return EXIT_SUCCESS;
}

/* function definitions */
int
get_lines(char* lines[])
{
    int     n = 0;
    char    buffer[80];     // temp storage for each line 

    puts("Enter one line at a time; enter a blank when done.");

    while (n < MAX && fgets(buffer, sizeof(buffer), stdin) != 0 && buffer[0] != '\n')
    {
        if (NULL == (lines[n] = (char*) malloc(strlen(buffer) + 1)))
            return -1;

        strcpy(lines[n++], buffer);
    }

    return n;
}

void
sort(char* s[], int size, int type)
{
    char*   x;

    // ptr to a function
    int (*compare)(char* s1, char* s2);

    // intialization
    compare = type ? reverse : alpha;

    for (int a = 1; a < size; a++)
    {
        for (int b = 0; b < size - 1; b++)
        {
            if (compare(s[b], s[b + 1]) > 0)
            {
                x = s[b];
                s[b] = s[b + 1];
                s[b + 1] = x;
            }
        }
    }
}

void
print(char* s[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%s\n", s[i]);

    return;
}

int
alpha(char* s1, char* s2)
{
    return strcmp(s2, s1);
}

int
reverse(char* s1, char* s2)
{
    return strcmp(s1, s2);
}
