/*
 * Name: unions.c
 * Desc:
 *      Demonstrate use of unions.
 */

#include <stdio.h>

union shared_tag {
    char c;
    int i;
    long l;
    float f;
    double d;
} shared;

void print_union(union shared_tag u);

int
main(void)
{
    shared.c = '$';
    print_union(shared);

    shared.d = 1234567.89;
    print_union(shared);

    shared.i = 9999;
    print_union(shared);

    return 0;
}

void print_union(union shared_tag u)
{
    printf("\nchar   c: %c\n", u.c);
    printf("int    i: %d\n", u.i);
    printf("long   l: %ld\n", u.l);
    printf("float  f: %f\n", u.f);
    printf("double d: %f\n", u.d);
    
    return;
}
