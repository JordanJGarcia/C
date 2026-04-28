/*
 * Name: test-stack.c
 * Desc:
 *      Test suite for stack.
*/

#include "../lib/stack.h"

#define MAX 11

static bool test_push(void);
static bool test_peek_top_pop(void);
static bool test_stack_size(void);
static bool test_empty_stack(void);

/* main */
int
main(void)
{
    if 
    (
        test_push()                 &&
        test_peek_top_pop()         &&
        test_stack_size()           &&
        test_empty_stack()
    )
    {
        puts("All tests passed!");
        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}

static bool
test_push(void)
{
    int i = 1;
    STACK *stack = NULL;
    STACK *node = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: push...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = push(i, &stack);
    for (node = stack, i = 1; node && node->value == i; node = node->next, i++) ;

    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS && empty_stack(&stack).rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}

static bool
test_peek_top_pop(void)
{
    int i = 1;
    STACK *stack = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: peek top and pop...");

    /* push values onto stack */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = push(i, &stack);
    while (peek(stack) == top(stack) && peek(stack) == pop(&stack) && !stack_empty(stack)) ;

    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS && stack_empty(stack));
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}

static bool
test_stack_size(void)
{
    int i = 1;
    STACK *stack = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: stack size...");

    /* push values onto stack */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = push(i, &stack);

    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS && stack_size(stack) == MAX - 1 && empty_stack(&stack).rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}


static bool
test_empty_stack(void)
{
    int i = 1;
    STACK *stack = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: empty stack...");

    /* push values onto stack */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = push(i, &stack);

    empty_stack(&stack);

    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS && stack_empty(stack));
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}
