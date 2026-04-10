# Lesson 8

Using Numeric Arrays

## Notes

* An ***array*** is a collection of data storage locations, each storing the same type of data and having the same name.
* Each storage location is called an *element*
* All of C's data types can be used for arrays.
* When you declare an array, the compiler sets aside a block of memory large enough to hold the entire array.
* *Single-dimensional* arrays have only a single subscript.
    - `float expenses[12];`
* *Multi-dimensional* arrays have more than one subscript.
    - `int checker[8][8];`
    - `int array[y-axis][x-axis][z-axis];`
    - There is no limit to the amount of dimensions. Don't get too crazy though!
* You can specify the number of elements with a literal constant `#define SIZE 12` but with most compilers you cannot do it with a symbolic constant `const SIZE = 12;`

### Initializing Arrays

* You can initialize all or part of an array when you first declare it.
    - `int array[4] = {1, 2, 3, 4};`
    - `int array[2][2] = { {1, 1}, {2, 2} };`
    - `int array[] = {1, 2, 3, 4};` Here the compiler will create an array just large enough to store all values.
    - `int array[10] = {1, 2, 3};` Per the ANSI standard, the remaining elements will be set to 0 here.
