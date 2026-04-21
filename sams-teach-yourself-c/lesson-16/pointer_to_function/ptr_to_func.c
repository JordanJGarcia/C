/*
 * Name: ptr_to_func.c
 * Desc:
 *      Demostrates use of pointers to functions.
*/

#include <stdio.h>

/* prototypes */
double  square(double x);
double  (*ptr)(double x);   // pointer to a func with a single double parameter that returns a double.
double  func1(double d, double (*p)(double));

#define VALUE 6.66
int
main(void)
{
    // initialize pointer to function
    ptr = square;

    // call 2 ways
    printf("square(%f) = %f\nptr(%f) = %f\nfunc1(%f, ptr) = %f", VALUE, square(VALUE), VALUE, ptr(VALUE), VALUE, func1(VALUE, ptr));

    return 0;
}

double
square(double x)
{
    return x * x;
}

double
func1(double d, double (*p)(double))
{
    return p(d);
}
