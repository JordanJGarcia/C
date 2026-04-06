/* This program displays a listing with line numbers */

#include <stdio.h>
#include <stdlib.h>

/* macros */
#define BUFF_SIZE 256

/* prototypes */
void usage(void);

/* globals */
int line;


/* main */
int main(int argc, char* argv[])
{
    char buffer[BUFF_SIZE];
    FILE *fp;

    if(argc < 2)
    {
        usage();
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error opening file: %s", argv[1]);
        return EXIT_FAILURE;
    }

    line = (1);

    while (fgets(buffer, BUFF_SIZE, fp) != NULL)
        fprintf(stdout, "%4d\t%s", line++, buffer);

    fclose(fp);
    return 0;
}

void usage(void)
{
    fprintf(stderr, "\nusage: list_it filename.ext\n");
}
