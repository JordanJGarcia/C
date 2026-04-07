/*
 * Name: sizeof.c
 * Desc:
 *      Display sizes of different C variable types in bytes.
*/

#include <stdio.h>

int main(void)
{
    printf("\nchar:                 %lu bytes", sizeof(char));
    printf("\nshort:                %lu bytes", sizeof(short));
    printf("\nint:                  %lu bytes", sizeof(int));
    printf("\nlong:                 %lu bytes", sizeof(long));
    printf("\nlong long:            %lu bytes", sizeof(long long));
    printf("\nunsigned char:        %lu bytes", sizeof(unsigned char));
    printf("\nunsigned short:       %lu bytes", sizeof(unsigned short));
    printf("\nunsigned int:         %lu bytes", sizeof(unsigned int));
    printf("\nunsigned long:        %lu bytes", sizeof(unsigned long));
    printf("\nunsigned long long:   %lu bytes", sizeof(unsigned long long));
    printf("\nfloat:                %lu bytes", sizeof(float));
    printf("\ndouble:               %lu bytes", sizeof(double));
    printf("\nlong double:          %lu bytes", sizeof(long double));

    return 0;
}
