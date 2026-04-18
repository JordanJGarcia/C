/*
 * Name: printf.c
 * Desc:
 *      Demonstrate use of printf().
*/

#include <stdio.h>

int
main(void)
{
    char * m1 = "Binary";
    char * m2 = "Decimal";
    char * m3 = "Octal";
    char * m4 = "Hexadecimal";

    float f = 10000.123;

    puts("Outputting a number with different field widths.\n");
    printf("%5f\n", f);
    printf("%10f\n", f);
    printf("%15f\n", f);
    printf("%20f\n", f);
    printf("%25f\n", f);

    puts("\nPress Enter to continue...");
    fflush(stdin);
    getchar();

    puts("\nUse the * field with specifier to obtain field width");
    puts("from a variable in the argument list.\n");

    for (int i = 5; i <= 25; i += 5)
        printf("%*f\n", i, f);

    puts("\nPress Enter to continue...");
    fflush(stdin);
    getchar();

    puts("\nInclude leading zeros.\n");
    printf("%05f\n", f);
    printf("%010f\n", f);
    printf("%015f\n", f);
    printf("%020f\n", f);
    printf("%025f\n", f);

    puts("\nPress Enter to continue...");
    fflush(stdin);
    getchar();

    puts("\nDisplay in octal, decimal, and hexadecimal.");
    puts("Use # to precede octal and hex output witha 0 and 0X."); 
    puts("Use - to left-justify each value in its field.");
    puts("First display column labels.\n");

    printf("%-15s%-15s%-15s", m2, m3, m4);
    for (int i = 1; i < 20; i++)
        printf("\n%-15d%-#15o%-#15X", i, i, i);

    puts("\nPress Enter to continue...");
    fflush(stdin);
    getchar();

    int n;
    puts("\n\nUse the %n conversion command to count characters.\n");
    printf("%s%s%s%s%n", m1, m2, m3, m4, &n);
    printf("\n\nThe last printf() output %d characters.\n", n);

    return 0;
}
