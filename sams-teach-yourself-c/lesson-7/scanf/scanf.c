/*
 * Name: scanf.c
 * Desc:
 *      Demonstrates the use of scanf()
 */

#include <stdio.h>

#define QUIT 4

int get_menu_choice(void);

int main(void)
{
    int choice = 0, i = 0;
    float f = 0.0;
    unsigned u = 0;

    while (choice != QUIT)
    {
        choice = get_menu_choice();

        if (choice == 1)
        {
            puts("\nEnter a signed decimal integer (i.e. -123): ");
            scanf("%d", &i);
        }

        if (choice == 2)
        {
            puts("\nEnter a decimal floating-point number (i.e. 1.23): ");
            scanf("%f", &f);
        }

        if (choice == 3)
        {
            puts("\nEnter an unsigned decimal integer (i.e. 123): ");
            scanf("%u", &u);
        }
    }

    printf("Your values are:\n\tint: %d\n\tfloat: %f\n\tunsigned: %u\n", i, f, u);

    return 0;
}


int get_menu_choice(void)
{
    int choice = 0;

    do
    {
        printf("\n");
        printf("\n1 - Get a signed decimal integer");
        printf("\n2 - Get a decimal floating-point number");
        printf("\n3 - Get an unsigned decimal integer");
        printf("\n4 - Quit");
        printf("\n");
        printf("\nEnter a selection: ");

        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);

    return choice;
}
