# Lesson 16

Pointers to Functions and Linked Lists

## Pointers to Functions
* When your program runs, the code for each function is loaded into memory starting at a specific address.
* A pointer to a function holds the starting address of a function -- its entry point.

### Declaring a Pointer to a Function
```
// type (*ptr_to_func)(parameter_list);

int     (*func1)(int x);
void    (*func2)(double y, double z);
char    (*func3)(char* p[]);
void    (*func4)();
```

### Initializing and Using a Pointer to a Function
```
float square(float x);  // prototype
float (*ptr)(float x);  // pointer declaration
float square(float x)   // definition
{
    return x * x;
}

ptr = square;   // initialize pointer
result = ptr(x);
```

## Understanding Linked Lists
* A *linked list* is a useful method of data storage that can easily be implemented in C.
* Pointers are central to linked lists.

### Basics of Linked Lists
```
struct person {
    char name[20];
    struct persion* next;
};
struct person *new, *head = NULL;
```
* Each data item in a linked list is contained in a structure.
* The structure also contains a pointer which provides the links in a linked list.
* The last element in a linked list is identified by the pointer element being assigned the value of `NULL`
* The first link is identified by a special pointer called the *head pointer*.

#### Adding an Element to the Beginning of a List
```
new = (struct person*) malloc(sizeof(struct person));
new->next = head;
head = new;
```
1. Create an instance of your structure, allocating memory for it using `malloc()`.
2. Set the next pointer of the new element to the current value of the head pointer.
3. Make the head pointer point to the new element.

#### Adding an Element to the End of the List
```
struct person *current = head;

while (current->next != NULL)
    current = current->next;

new = (struct person*) malloc(sizeof(struct person));
current->next = new;
new->next = NULL;
```
1. Create an instance of your structure, allocating memory using `malloc()`.
2. Set the next pointer in the last element to point to the new element.
3. Set the next pointer in the new element to `NULL` to signal that it is the last item in the list.

#### Adding an Element to the Middle of the List
```
struct person *marker = NULL;

/* code to set marker to point to the desired list location */

new = (struct person*) malloc(sizeof(struct person));
new->next = marker->next;
marker->next = new;
```
1. Locate the existing element that teh new element will be placed after.
2. Create an instance of your structure, allocating memory using `malloc()`
3. Set the next pointer of the new element to the next pointer of the marker element.
4. Set the next pointer of the marker element to point to the new element.

#### Deleting an Element from the List
* This simply involves manipulating pointers and freeing the memory used by the deleted list element.

##### First Element
```
temp = head;
head = head->next;
free(temp);
```
* To delete the **first element**, set the head pointer to point to the second element in the list.

##### Last Element
```
struct person *p1, *p2;
p1 = head;
p2 = p1->next;

while (p2->next != NULL)
{
    p1 = p2;
    p2 = p1->next;
}

free(p2);
p1->next = NULL;

// I don't understand why this part is needed.
if (head == p1)
    head = NULL;
```
* To delete the **last elemetn**, set the next pointer of the next-to-last element to `NULL`.

##### Any Other Element
```
struct person *p1, *p2;

/* code to have p1 point to the element before the one to be deleted */

p2 = p1->next;
p1->next = p2->next
free(p2);
```
* To delete **any other element**, set the next pointer of the element before the one being deleted to point to the element after the one being deleted.
