# Lesson 7

Fundamentals of Reading and Writing Information

## Notes

### printf()
```
#include <stdio.h>
printf(format-string[, arguments,...]);
```
* Prints formatted information to the standard output device.
* Part of the standard C library and is included as part of the ANSI standard
* Has 2 arguments (**format string** & **variables**):
    - **Format string** can contain 3 components:
        - *Literal text* is displayed exactly as entered.
        - *Conversion specifers* consist of the percent sign (%) followed by a character.

			Conversion Specifier | Meaning | Types Converted
			:-------------------:|---------|----------------
			`%c`     | Single character | `char`
			`%d`     | Signed decimal integer | `int, short`
			`%ld`    | Signed long decimal integer | `long`
			`%f`     | Decimal floating-point number | `float, double`
			`%s`     | Character string | `char` arrays
			`%u`     | Unsigned decimal integer | `unsigned int, unsigned short`
			`%lu`    | Unsigned long decimal integer | `unsigned long`

        - *Escape Sequences* consist of a backslash (\\) followed by a single character.

			Sequence | Meaning
			:-------:|--------
			`\a`     | Bell (alert)
			`\b`     | Backspace
			`\f`     | Form Feed
			`\n`     | Newline
			`\r`     | Carriage return
			`\t`     | Horizontal tab
			`\v`     | Vertical tab
			`\\`     | Backslash
			`\?`     | Question mark
			`\``     | Single quotation
			`\"`     | Double quotation

    - **Variable(s)** can be any valid C expression.

### puts()
```
#include <stdio.h>
puts(string);
```
* Cannot display numeric variables.
* Takes a single string as its argument and copys it to the standard output device. 
* ***automatically adds a newline at the end***
* You can include escape sequences.

### scanf()
```
#include <stdio.h>
scanf(format-string[, arguments, ...]);
```
* Reads data from the keyboard according to a specified format and assigns the input data to one or more program variables.
* A single `scanf()` can input more than one value if you include multiple conversion specifiers.
    - `scanf("%d %f", &x, &y);`
    - Uses white space to separate input into fields (spaces, tabs, or newlines).


