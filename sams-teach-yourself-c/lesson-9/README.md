# Lesson 9

Understanding Pointers

## Notes

### Your Computer's Memory
* RAM consists of many millions of *sequential* storage locations, each identified by a unique address.
* When you declare a variable in C, the compiler sets aside a memory location with a unique address to store that variable.

### Creating a Pointer
* The address of a variable is a number and can be treated like any other number in C.
* If you know a variable's address, you can create a variable to store that address.
* A pointer is a variable that stores the address of another variable.

### Pointers and Simple Variables
#### Declaring Pointers
`typename *ptrname;`
* A pointer is a numeric variable, and like all other variables, must be declared before it can be used.
* `*` is the *indirection operator*.
#### Initializing Pointers
`pointer = &variable;`
* You can't do anything with a declared pointer until you make it point at something.
* You use the *address-of operator* `&`, which returns the address of a variable when placed before it.
#### Using Pointers
* You use the *indirection operator* `*` to refer to the content of the variable pointed to by the pointer.
* Accessing the contents of a variable by using the variable name is *direct access*.
* Accessing the contents of a variable by using a pointer to the variable is *indirect access* or *indirection*, often called *dereferencing*.

### Pointers and Variable Types
* Each individual byte of memory has its own address.
* A multibyte variables contain multiple addresses, but the pointer points to the first (lowest) byte it occupies.
* A pointer is declared to point to a certain type of variable, so the compiler knows how many bytes it occupies.

### Pointers and Arrays
#### The Array Name as a Pointer
* An array name without brackets is a pointer to the array's first element.
* Say you have an array `data[]` then `data` is the *address* of the first array element. `data == &data[0])`
* The name of an array is a *pointer constant*, it can't be changed and remains fixed for the entire time the program executes.
* You can, however, create a pointer to point to the array and that won't be a constant.
    - *pointer_to_array* can be modified to point elsewhere, whereas *array* cannot.
```
int array[100], *pointer_to_array;
/* additional code */
pointer_to_array = array;
```


#### Array Element Storage
* Each array element is stored *n* bytes higher than the previous element.
    - *n* is the size of the element type. (i.e. short is 2 bytes, float is 4 bytes, etc.)

#### Pointer Arithmetic
* Allows you to increment or decrement a pointer (non-constant) by an amount equal to the size of the data type stored in the array.
* *Increment* (`pointer++;` or `pointer += n;`) to move to next element(s).
* *Decrement* (`pointer--;` or `pointer -= n;`) to move to previous element(s).

#### Other Pointer Manipulations
* *Differencing* is subtracting 2 pointers. `ptr1 - ptr2`
    - If you have 2 pointers to different elements of the same array, you can subtract them to see how far apart they are.
    - Pointer arithmetic will return number of elements as the distance apart.
* *Comparing* pointers. `ptr1 < ptr2`
    - Can use any relational operator.
    - The example above would return true if `ptr1` points to an earlier member of the array than ptr2.

#### Array Subscript Notation and Pointers
* You can access the elements of an array using the indirection operator.
```
*(array) == array[0]
*(array + 1) == array[1]
*(array + 2) == array[2]
...
*(array + n) == array[n]
```

#### Passing Arrays to Functions
* The only way to pass an entire array to a function is by using a pointer.

### Pointer Cautions
* When you write a program that uses pointers, you must avoid one serious error:
    - Using an uninitialized pointer on the left side of an assignment statement.
    - `int *ptr;` does not point to *anything known*, so doing something like `*ptr = 12;` will assign the value 12 to whatever
       address `ptr` points to, which could be disastrous (i.e. if its OS code).

