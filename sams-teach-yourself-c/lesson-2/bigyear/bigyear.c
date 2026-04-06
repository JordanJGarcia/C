#include <stdio.h>
#include <stdlib.h>

#define TARGET_AGE 88

int year;

int calcYear(int year);

int main(void)
{
    // ask user for birth year
    printf("What year was the subject born? ");
    printf("Enter as a 4-digit year (YYYY): ");
    scanf(" %d", &year);
    printf("Someone born in %d will be %d in %d.",
            year, TARGET_AGE, calcYear(year));
    
    return EXIT_SUCCESS;
}

int calcYear(int year)
{
    return (year + TARGET_AGE);
}
