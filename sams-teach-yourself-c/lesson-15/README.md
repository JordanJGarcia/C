# Lesson 15

Pointers to Pointers and Arrays of Pointers

## Declaring Pointers to Pointer
```
int my_var = 12;
int *ptr_to_my_var = &my_var;
int **ptr_to_ptr = &ptr_to_my_var;

// the following statements are equivalent
*ptr_to_my_var = 12;
**ptr_to_ptr = 12;
```
* A *pointer* is a numeric variable with a value that is the address of another variable.
* Because a pointer is itself a numeric variable, it is stored in your computer's memory at a particular address.
    - Therefore you can create a pointer to a pointer, a variable whose value is the address of a pointer.
* Declaring and using a pointer to a pointer is called *multiple indirection*.

## Pointers and Multidimensional Arrays
```
// 2 rows, 4 columns
int multi[2][4];
```
* In the above example, you can imagine it as follows:
    - `multi` is a 2-element array
    - Each element in multi is a 4-element array of type int.
* `multi` is **a pointer** to the first array element, which is an array of 4 ints.
* `multi[0]` is **a pointer** to the first array element, which is an int.
* `multi[0][0]` is **array data**; the first element in `multi[0]`, an int.

## Working with Arrays of Pointers
```
char* msg[10] = { "one", "two", "three" };
```
* The most common use is an array of strings.
* The above example does the following:
    - It allocates a 10-element array named `message`; each element is a pointer to type `char`.
    - It allocates space somewhere in memory and stores the three initialization strings, each with a terminating null character.
    - It initializes `message[0]` to point to the first `char` of the string "one", `message[1]` to point to the first `char` of the string "two", and `message[2]` to point to the first `char` of the string "three".
    
