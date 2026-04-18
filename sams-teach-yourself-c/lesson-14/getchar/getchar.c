/* 
 * Name: getchar.c
 * Desc:
 *      Demonstrates getchar().
 */

#include <stdio.h>

#define MAX 80

void basic_use(void);
void input_entire_line_of_text(void);

int
main(void)
{
    basic_use();
    puts("");
    input_entire_line_of_text();

    return 0;
}

/* this just displays the line one char at a time to stdout */
void
basic_use(void)
{
    int c;

    while ((c = getchar()) != '\n')
        putchar(c);

    return;
}

/* this stores it in a string for more use */
void
input_entire_line_of_text(void)
{
    /* Can do either char or int I guess */
    char c, buffer[MAX + 1];
    int i = 0; 

    for (; (c = getchar()) != '\n' && i < MAX; i++)
        buffer[i] = c;

    buffer[i] = '\0';

    printf("%s\n", buffer);

    return;
}
