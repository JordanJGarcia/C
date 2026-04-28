#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./result.h"

/* stack is linked-list based */
#include "./dll.h"

typedef DLL_NODE STACK;

/* manipulate */
los_t   push(const int value, STACK **stack);
int     pop(STACK **stack);
los_t   empty_stack(STACK **stack);

/* read */
int     peek(STACK *stack);     // do the same thing
int     top(STACK *stack);      // do the same thing

/* check */
bool    stack_empty(STACK *stack);
int     stack_size(STACK *stack);
void    print_stack(STACK *stack);

#endif
