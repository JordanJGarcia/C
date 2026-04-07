/*
 * Name: agechecker.c
 * Desc:
 *      Demonstrates if statements and some of C's relational operators.
*/

#include <stdio.h>

/* preprocessor directives */

#define CURRENTYEAR 2026

int main(void)
{
    int birth_year, age;

    printf("Enter the year you were born: ");
    scanf("%d", &birth_year);

    // calculate whether user was born during leap year
    if (birth_year % 4 == 0)
        printf("You were born in a leap year!\n");
    else
        printf("You were not born in a leap year!\n");

    age = CURRENTYEAR - birth_year;

    // check voting/drinking age
    if (age >= 18)
        printf("You can vote this year!\n");

    if (age <= 21)
        printf("It is illegal for you to drink alcohol!\n");

    return 0;
}
