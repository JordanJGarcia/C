# Lesson 11

Implementing Structures, Unions, and Typedefs

## Notes

### Working with Structures
* A *structure* is a collection of one or more variables grouped under a single name for easy manipulation.
    - Can contain any of C's data types, including arrays and other structures.
* Each variable within a structure is called a *member* of the structure.

#### Defining and Declaring Structures
```
struct tag {
    structure_member(s);
    /* additional statements */
} instance;
```
* The *struct* keyword identifies the beginning of a structure definition.
    - Must be followed immediately by the name of the structure, also known as the *tag* or *type name*.
* There are 2 ways to declare structures:
    - One is to follow the structure definition with a list of one or more variable names.
    - The other is to declare structure variables at a different location in your source code from the definition.

#### Accessing Members of a Structure
* Structure members are accessed using the *structure member operator* `.`, also called the *dot operator*.
`printf("%d", tag.member);`
* One major advantage of using structures is that you can copy information between structures of the same type with a simple equation statement. `first = second;`
    - Note that for pointers, this will just copy the address and they will refer to the same area in memory.

#### Initializing Structures
* Like other C variable types, structures can be initialized when they are declared.
```
struct sale {
    char customer[20];
    char item[20];
    float amount;
} mysale = {
               "Acme Industries",
               "Left-handed widget",
               1000,00
           };
```

### Structures and Pointers

#### Pointers as Structure Members
```
struct data {
    int* value;
    int* rate;
} first;
```
* As with all pointers, declaring them is not enough; you must also initialize them to point to something.
```
first.value = &cost;
first.rate = &interest;
```
* Perhaps the type of pointer most frequently used as a structure member is a pointer to type `char`.
    - To refresh your memory you can declare a pointer to type `char` and initialize it to point at a string as follows:
```
char* msg;
msg = "Teach Yourself C In One Hour a Day";
```
* You can do the same thing with pointers to type `char` within structures.
```
struct msg {
    char* m1;
    char* m2;
} my_msg;

my_msg.m1 = "Teach Yourself C In One Hour a Day";
my_msg.m2 = "By SAMS Publishing";
```
* If you define a structure that contains an array of type `char` rather than a pointer to type `char`, every instance of that structure type contains storage space for an array of the specified size.
    * You will also be limited to the size of the char array.
```
struct msg {
    char m1[30]; /* each instance will have a char array of size 30 bytes */
    char* m2;    /* each structure will be able to hold the address of a spot in memory, but it must be initialized first. */
};
```

#### Pointers to Structures
```
struct part {
    short number;
    char name[10];
};

struct part* pointer_to_part;
struct part my_part;
pointer_to_part = &my_part;
my_part->number = 100;
```
* Often used to pass structures as arguments to functions.
* Also used in a powerful data storage method known as *linked lists*.
* You must declare an instance of the struct before anything can point to it.
    - Remember it is a ***declaration***, not a definition, which sets aside storage space in memory for a data object.
* Use the *indirect membership operator* `->` to access structure members using a pointer to the structure.
* When accessing members via a pointer to the structure, the following 3 expressions are all equivalent:
```
structure.member;
(*pointer_to_structure).member;
pointer_to_structure->member
```
* If you have an array of structures, you can use *pointer arithmetic* to navigate through them.
```
struct part data[100];
struct part* ptr_to_part = data;
// or
// struct part* ptr_to_part = &data[0];
ptr_to_part++;      // goes to next struct in array
ptr_to_part += 5;   // goes 5 structs up
```

#### Passing Structures as Arguments to Functions
* Like other data types, a structure can be passed as an argument to a function.
```
void print_rec(struct data record)
{
    printf("Donor %s %s game $%.2f.\n", record.fname, record.lname, record.amount);
}
```
### Creating Synonyms for Structures with `typedef`
```
typedef struct {
    int x;
    int y;
} coord;

coord top_left, bottom_right;
```

### Understanding Unions
```
union shared {
    char c;
    int i;
};

union shared my_var = {'@'};
```
* Declared and used in the same way as structures
* Differs from a structure in that only one of its members can be used at a time.
    - All members of a union occupy the same area of memory -- they are laid on top of one another.
* Can be initialized on its declaration, but since only one member can be used at a time, only one member can be initialzed.
