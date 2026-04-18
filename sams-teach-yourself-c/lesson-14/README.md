# Lesson 14

Working with the Screen, Printer, and Keyboard.

## Notes

### Streams and C
* **All C input/output is done with streams**, no matter where input is coming from or where output is going to.

#### What Is a Stream?
* A *stream* is a sequence of bytes of data.
    - A sequence of bytes flowing into a program is an *input stream*
    - A sequence of bytes flowing out of a program is an *output stream*
* The major advantage of streams is that input/output programming is *device-independent*.
* Every C stream is connected to a file.
    - In this context, the term file does not refer to a disk file.
    - Rather, it is an intermediate step between the stream that your program deals with and the actual physical device used for input or output.
    - The details of interactions among streams, files, and devices are taken care of automatically by the C library functions and the operating system.

#### Text Versus Binary Streams
* C streams fall into two modes: *text* and *binary*.
    - A *text* stream consists only of characters, such as text data sent to the screen.
        - Organized into lines, which can be up to 255 characters long, and are terminated by an end-of-line, or newline, character.
        - **This lesson is about text streams.**
    - A *binary* stream can handle any sort of data, including, but not limited to, text data.
        - Bytes of data in a binary stream are not translated or  interpreted in any special way; they are read and written exactly as-is.
        - Used primarily with disk files.

#### Predefined Streams
* The ANSI standard for C has 3 predefined streams:
    - `stdin`
    - `stdout`
    - `stderr`
* These streams are automatically opened when a C program starts executing, and automatically closed when the program terminates.
* They are all text-mode streams.
* The standard streams are opened automatically, but other streams, such as those used to manipulate information stored on disk, must be opened explicitly.

### Using C's Stream Functions
* Most of C's stream input/output functions come in 2 varieties:
    - One that always uses one of the standard streams.
    - One that requires the programmer to specify the stream.

#### Some Functions In `<stdio.h>`


Standard Streams | Requires a Stream Name | Description | Additional Library Requirements
:---------------:|:----------------------:|-------------|--------------------------------
`printf()` | `fprintf()` | Formatted output | 
`vprintf()` | `vfprintf()` | Formatted output with a variable argument list | `<stdargs.h>`
`puts()` | `fputs()` | String output |
`putchar()` | `putc()`, `fputc()` | Character output |
`scanf()` | `fscanf()` | Formatted Input |
`vscanf()` | `vfscanf()` | Formatted Input with a variable argument list |
`gets()` | `fgets()` | String Input | 
`getchar()` | `getc()`, `fgetc()` | Character input |
`perror()` |  | String output to stderr only | `<stdlib.h>`


### Accepting Keyboard Input
* Input functions are divided into a hierarchy of 3 levels:
    - Character input
    - Line input
    - Formatted input

#### Character Input
* Read input from a stream one character at a time.
* Each of the following functions return the next character in the stream, or `EOF` if the end of file has been reached or an error has occured.
    - `EOF` is a symbolic constant defined in `<stdio.h>`, set to `-1`.
* Character input functions differ in terms of buffering and echoing:
    - With *buffered* functions, the operating system holds all characters in a temporary storage space until you press Enter, then sends the characters to the `stdin` stream.
    - With *unbuffered* functions, each character is send to `stdin` as soon as the key is pressed.
    - Some input functions automatically *echo* each character to `stdout` as its is received.
    - Others don't echo; the character is sent to `stdin` and not `stdout`.

##### `getchar()`
```
#include <stdio.h>

int getchar(void);
```
* Obtains the next characer from the stream `stdin`.
* Buffered, echoes.


##### `getch()` && `getche()`
```
int getch(void);
int getche(void); // exactly the same but echoes
```
* Obtains the next character frm the stream `stdin`.
* Unbuffered, no echo.
* Not part of the ANSI standard, so might not be available on every system.


##### `getc()` && `fgetc()`
* Don't automatically work with `stdin`, must specify input stream.
* Used primarily to reach characters from disk files.
* More about this in [lesson 17](https://github.com/JordanJGarcia/C/tree/development/sams-teach-yourself-c/lesson-17)

##### `ungetc()`
```
#include <stdio.h>

int ungetc(int ch, FILE * fp);
```
* Return a character to the input stream, where it will be the first character read by the next input operation on that stream.
    * `int ch` argument is the character to be returned.
    * `FILE * fp` is the stream it is to be returned to.
    * Can only unget a single character, can never unget `EOF`.
* Returns `ch` on success, `EOF` if teh character can't be returned to the stream.

#### Line Input
* Read a line from an input stream.
* Standard library has 2:
    - `gets()`
    - `fgets()`

##### `gets()`
```
#include <stdio.h>

char * gets(char * str);
````
* Reads a line from `stdin` until a newline `\n` or `EOF` and stores it in `str`.
* `\n` is replaced with a null character.
* Returns a pointer to `str` (the same string), or `NULL` on error.
* You must allocate sufficient memory space before calling `gets()`.

##### `fgets()`
```
#include <stdio.h>

char * fgets(char * str, int n, FILE * fp);
```
* Reads a line of text, up to `int n - 1` characters or `\n` or `EOF`, from input stream `FILE * fp`, and stores it in `char * str`.
* Returns a pointer to `str` (the same string), or `NULL` on error.
* The newline is included in `str` and null terminated before being stored.
* Often used to input text from disk files.


### Working with Formatted Input
* Allow you to read in numeric types and format the input.

#### [`scanf()`](https://github.com/JordanJGarcia/C/tree/development/sams-teach-yourself-c/lesson-7#scanf) && `fscanf()`
```
#include <stdio.h>
scanf(const char * format, ...);
fscanf(FILE * stream, const char * format, ...);
```
* Reads data from the input stream according to a specified format and assigns the input data to one or more program variables.
* Buffered; no characters are received from `stdin` until the user presses Enter.
* Extra characters, if any, remain waiting in `stdin`
* Type specifier characters used in `scanf()` conversion specifiers:


Type | Argument | Meaning of Type
:---:|----------|----------------
`d` | `int *` | A decimal integer.
`i` | `int *` | An integer in decimal, octal (with leading 0), or hexadecimal (leading 0X or 0x) notation.
`o` | `int *` | An integer in octal notation with or without the leading 0.
`u` | `unsigned int *` | An unsigned decimal integer.
`x` | `int *` | A hexadecimal integer with or without the leading 0x.
`c` | `char *` | One or more characters are read and assigned sequentially to the memory location indicated by the argument. No terminating `\0` is added. If a field width argument is given, that number of characters, including whitespace (if any), is read.
`s` | `char *` | A string of nonwhite-space characters is read into the specified memory location, and a terminating `\0` is added.
`a,e,f,g` | `float *` | A floating-point number. Numbers can be input in decimal or scientific notation.
`[...]` | `char *` | A string. Only the characters listed between teh brackets are accepted. Input ends as soon as a nonmatching character is encountered, the specified field width is reached, or Enter is pressed. To accept the `]` character, list it first: `[]...]`. A `\1` is added at the end of the string.
`[^...]` | `char *` | Same as above, except that only characters not listed between the brackets are accepted.
`%` | None | Literal `%`: Reads the `%` character. No assignment is made.

#### `fflush()`
```
#include <stdio.h>

int fflush(FILE * stream);
```
* Flushes the information in `FILE * stream`.

### Controlling Output to the Screen
* Screen output functions are divided into 3 general categories:
    - character output
    - line output
    - formatted output

#### `putchar()`, `putc()`, and `fputc()`
```
#include <stdio.h>

/*
 * writes to stdout
 * returns character just written, or EOF (-1)
*/
int putchar(int c); // sends to stdout

/*
 * macro implementation of fputc()
*/
int putc(int c, FILE * fp);
int fputc(int c, FILE * fp);
```
* Send a single character to a stream.

#### `puts()` and `fputs()`
```
#include <stdio.h>

int puts(char * cp);
int fputs(char * cp, FILE * fp);
```
* Sends a string to a stream.
* Displays the entire string up to but not including the terminating null character.
* Returns positive value on success, EOF (-1) on error.

#### `printf()` and `fprintf()`
```
#include <stdio.h>

/* I am not sure if these return void... */
void printf(const char * format, ...);
void fprintf(FILE * fp, const char * format, ...);
```
* To display numbers, you must use the C library's formatted output functions.
* Can also display strings and characters.
* Conversion command format:
    - `%[flag][field_width][.[precision]][l]conversion_char`
        - `conversion_char` is only required part.


	        Conversion Character | Meaning
	        :-------------------:|--------
	        `d` | Display a signed integer in decimal notation.
	        `u` | Display a unsigned integer in decimal notation.
	        `o` | Display an integer in unsigned octal notation.
	        `x`,`X` | Display an integer in unsigned hexadecimal notation, Use `x` for lowercase output and `X` for uppercase.
	        `c` | Display a single character. (The argument gives the character's ASCII code.)
	        `e`,`E` | Display a float or double in scientific notation. Six digits display to the right of the decimal point untiless another precision is specified with the `f` specifier. `e` for lowercase, `E` for uppercase.
	        `f` | Display a float or double in decimal notation. Six digits display to the right of the decimal unless another precision is specified.
	        `g`,`G` | Use `e`, `E`, or `f` format. `e` or `E` format is used if the exponent is less that -3 or greater than the precision (which defaults to 6). `f` format is used otherwise. Trailing zeros are truncated.
	        `n` | Nothing is displayed. The argument corresponding to an `n` conversion command is ap ointer to type `int`. The `printf()` function assings to this variable the number of characters output so far. 
	        `s` | Display a string. The argument is a pointer to type `char`. Characters display until a null character is encountered or the number of characters specified by precision display. The terminating null character is not output.
	        `%` | Display the `%` character.
	        `g`,`G` | Use `e`, `E`, or `f` format. `e` or `E` format is used if the exponent is less that -3 or greater than the precision (which defaults to 6). `f` format is used otherwise. Trailing zeros are truncated.
	
	        Flag | Meaning
	        :---:|--------
	        `-` | Output is left-justified (right-justified is default)
	        `+` | Signed numbers always display with a leading + or -
	        `' '` | A space means that positive numbers are preceded by a space
	        `#` | This applies only to `x`, `X`, and `o` conversion characters. It specifies that nonzero numbers display with a leading `0X` or `0x` (for `x`/`X`) or `0` (for `o`)
