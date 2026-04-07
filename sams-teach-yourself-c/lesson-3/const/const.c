/*
 * Name: const.c
 * Desc:
 *      Demonstrates variables and constants.
*/

#include <stdio.h>

/* preprocessor directives */
#define LAPS_PER_MILE 4

int main(void)
{
    const int CURRENT_YEAR = 2026;
    float miles;
    int laps, birth_year, age;

    /* input data from user */
    printf("How many laps did you run? ");
    scanf("%d", &laps);
    printf("What year were you born? ");
    scanf("%d", &birth_year);

    /* perform conversions */
    miles = (float)laps/LAPS_PER_MILE;
    age = CURRENT_YEAR - birth_year;

    /* display results */
    printf("\nYou ran %.2f miles.", miles);
    printf("\nNot bad for someone turning %d  this year!\n", age);

    return 0;
}
