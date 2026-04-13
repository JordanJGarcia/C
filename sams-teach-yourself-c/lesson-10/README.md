# Lesson 10

Working with Characters and Strings

## Notes

### The `char` Data Type
* `char` is one of C's numeric integer data types.
* Your computer's memory stores all data in numeric form.
* *ASCII code* or *ASCII character set* is the standardized transformation of characters to integers (between 0 and 255).

### Using Character Variables
* To create literal character constants, you enclose a single character in single quotation marks.
* The compiler automatically translates literal character constants into the corresponding ASCII codes, and the numeric code value is assigned to the variable.

### Using Strings
* In C, a string is defined as a sequence *(array)* of characters ending with the *null character* `\0`.
* You will need to create an array with a size of the string length + 1 (for null-terminator).
#### Initialiing Character Arrays (Strings)
* `char string[10] = { 'A', 'l', 'a', 'b', 'a', 'm', 'a', '\0' };`
* `char string[10] = "Alabama";` or `char string[] = "Alabama";`
    - It is more convenient to use a *literal string* as above.
    - When you use a literal string, the compiler automatically appends a null-terminator to the string.
    - If you don't specify the number of subscripts when you declare the array, the compiler calculates the size of the array for you.

### Strings Without Arrays
* There are 2 methods to allocate space for a string without using an array.
    - Allocating space at compilation. `char * msg = "This is my string";`
    - Allocating space dynamically. `malloc()`
#### `char * msg = "This is my string";`
* This declares a pointer to a char and initializes `msg` to point to the first char in the string.
* Must be declared/initialized on the same line.
* Can also write as `char msg[] = "This is my string";`.

#### The `malloc()` Function
```
#include <stdlib.h>
void* malloc(size_t size);
```
* One of C's *memory allocation* functions.
* You pass it the number of bytes of memory needed.
* It returns an address (pointer to the first byte in the block of memory), or NULL if it cannot allocate the space.

### Displaying Strings and Characters
* `puts()`
* `printf()` with the `%s` format specifier.

### Reading Strings from the Keyboard
* `gets()`
    - Reads all characters typed at the keyboard up to the first newline character.
    - Automatically appends null-terminator.
    - Be careful that string isn't oversized for allocated space.
    - Returns a pointer to the string just read, or NULL.
```
#include <stdio.h>
char* gets(char* str);
```
* `scanf()` with the `%s` or `%ns` format specifiers.
    - `%ns` reads up to n characters or the first white-space character, whichever comes first.
    - You can read in multiple strings: `scanf("%s%s%s", s1, s2, s3);`
    - If you enter more strings than expected, the extra strings are stored in the keyboard buffer and picked up in the next `scanf()` or other input calls.
    - Returns the number of items successfully inputted.
