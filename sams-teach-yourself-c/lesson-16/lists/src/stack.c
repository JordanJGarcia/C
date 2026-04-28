/*
 * Name: stack.c
 * Desc:
 *      Implementation of a stack.
*/

#include "../lib/stack.h"

los_t
push(const int value, STACK **stack)
{
    /* add value to end of list */
    los_t result = add_to_dll(value, stack, -1);

    if (result.rc == MEMORY_ERROR) return result;

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "pushed to stack", value);
}


/* i guess the stack can only hold positive values, or values != EMPTY */ 
int
pop(STACK **stack)
{
    /* remove value from end of list */
    los_t result = del_pos_from_dll(-1 ,stack);

    if (result.rc == EMPTY) return EMPTY;

    return result.value;
}


int
peek(STACK *stack)
{
    STACK *node = stack;

    if (dll_is_empty(node)) return EMPTY;

    for(; node->next; node = node->next) ;

    return node->value;
}


int
top(STACK *stack)
{
    return peek(stack);
}


los_t
empty_stack(STACK **stack)
{
    return empty_dll(stack);
}


bool
stack_empty(STACK *stack)
{
    return !stack;
}


int
stack_size(STACK *stack)
{
    if (stack_empty(stack))
        return 0;

    int size = 1;
    STACK *node = stack;

    for(; node->next; node = node->next, size++) ;

    return size;
}


void
print_stack(STACK *stack)
{
    if (stack_empty(stack))
    {
        puts("\nstack empty.");
        return;
    }

    STACK *node = stack;

    puts("");
    do
    {
        printf("%d\n", node->value);
        node = node->next;
    } 
    while (node);
}
