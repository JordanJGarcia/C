/*
 * Name: multi.c
 * Desc:
 *      Demonstrates the use of multi-dimensional arrays.
*/

#include <stdio.h>

int
main(void)
{
    int multi[2][4];

    char* s[2] = { "hello", "there" };

    printf("multi = %p\n", multi);
    printf("multi[0] = %p\n", multi[0]);
    printf("&multi[0][0] = %p\n", &multi[0][0]);

    printf("\nsizeof(multi) = %lu\n", sizeof(multi));
    printf("sizeof(multi[0]) = %lu\n", sizeof(multi[0]));
    printf("sizeof(multi[0][0]) = %lu\n", sizeof(multi[0][0]));

    printf("\ns: { \"%s\", \"%s\" }\n", s[0], s[1]);
    printf("sizeof(s) = %lu\n", sizeof(s));
    printf("sizeof(s[0]) = %lu\n", sizeof(s[0]));
    printf("sizeof(s[0][0]) = %lu\n", sizeof(s[0][0]));

    char* c_ptr = NULL;
    printf("\nchar* c_ptr = NULL;\n");
    printf("\nsizeof(c_ptr) = %lu\n", sizeof(c_ptr));

    int* i_ptr = NULL;
    printf("\nint* i_ptr = NULL;\n");
    printf("\nsizeof(i_ptr) = %lu\n", sizeof(i_ptr));

    float* f_ptr = NULL;
    printf("\nfloat* f_ptr = NULL;\n");
    printf("\nsizeof(f_ptr) = %lu\n", sizeof(f_ptr));

    struct random {
        int i;
        char c;
        float f;
    } st;

    struct random* st_ptr = NULL;
    printf("\nstruct random* st_ptr = NULL;\n");
    printf("\nsizeof(st_ptr) = %lu\n", sizeof(st_ptr));

    return 0;
}
