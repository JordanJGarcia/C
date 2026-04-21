/*
 * Name: dll-test.c
 * Desc:
 *      Test suite for doubly-linked list.
*/

#include "../lib/dll.h"

#define MAX 11

static bool test_add_to_front(void);
static bool test_add_to_middle(void);
static bool test_add_to_end(void);

static bool test_del_from_front(void);
static bool test_del_from_middle(void);
static bool test_del_from_end(void);
static bool test_del_val(void);
static bool test_del_nonexistent_val(void);
static bool test_del_nonexistent_pos(void);

/* main */
int
main(void)
{
    test_add_to_front();
    test_add_to_middle();
    test_add_to_end();
    test_del_from_front();
    test_del_from_middle();
    test_del_from_end();
    test_del_val();
    test_del_nonexistent_val();
    test_del_nonexistent_pos();
    return 0;
}

static bool
test_add_to_front(void)
{
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int i, result = EXIT_SUCCESS;
    
    printf("%-40s", "TEST: add to front...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, 1);
    for (node = list, i = MAX - 1; node && node->value == i; node = node->next, i--) ;

#define IS_SUCCESS i == 0 && result == EXIT_SUCCESS
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}


static bool
test_add_to_middle(void)
{
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int i, result = EXIT_SUCCESS;
    int expected[] = { 1, 2, 3, 4, 10, 9, 8, 7, 6, 5 };
    
    printf("%-40s", "TEST: add to middle...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, (MAX / 2));
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

#define IS_SUCCESS i == MAX - 1 && result == EXIT_SUCCESS 
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_add_to_end(void)
{
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int i, result = EXIT_SUCCESS;
    
    printf("%-40s", "TEST: add to end...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    for (node = list, i = 1; node && node->value == i; node = node->next, i++) ;

#define IS_SUCCESS i == MAX && result == EXIT_SUCCESS 
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_from_front(void)
{
    DLL_NODE *list = NULL;
    int i, result = EXIT_SUCCESS;

    printf("%-40s", "TEST: delete from front...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    empty_dll(&list);

#define IS_SUCCESS dll_is_empty(list) && result == EXIT_SUCCESS 
    printf(IS_SUCCESS ? "success\n": "failure\n");
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_from_middle(void)
{
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int i, result = EXIT_SUCCESS;
    int expected[] = { 1, 2, 3, 4, 6, 7, 8, 9, 10 };

    printf("%-40s", "TEST: delete from middle...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    del_pos_from_dll((MAX / 2), &list);
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

#define IS_SUCCESS !node && i == MAX - 2 && result == EXIT_SUCCESS 
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_from_end(void)
{
    DLL_NODE *list = NULL;
    int i, result = EXIT_SUCCESS;

    printf("%-40s", "TEST: delete from end...");

    for (i = 1; i < MAX && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    while (del_pos_from_dll(-1, &list) != LIST_EMPTY) ;

#define IS_SUCCESS dll_is_empty(list) && result == EXIT_SUCCESS
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_val(void)
{
    DLL_NODE *list = NULL;
    int i, result = EXIT_SUCCESS;

    printf("%-40s", "TEST: delete val...");

    for (i = 0; i < MAX - 1 && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    for (i = MAX - 2; i >= 0 && del_val_from_dll(i, &list) != LIST_EMPTY; i--);

#define IS_SUCCESS dll_is_empty(list) && result == EXIT_SUCCESS
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_nonexistent_val(void)
{
    DLL_NODE *list = NULL;
    int i, rc, result = EXIT_SUCCESS;

    printf("%-40s", "TEST: delete nonexistent val...");

    for (i = 0; i < MAX - 1 && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    rc = del_val_from_dll(-9999, &list);

#define IS_SUCCESS result == EXIT_SUCCESS && rc == VALUE_NOT_FOUND
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}

static bool
test_del_nonexistent_pos(void)
{
    DLL_NODE *list = NULL;
    int i, rc, result = EXIT_SUCCESS;

    printf("%-40s", "TEST: delete nonexistent val...");

    for (i = 0; i < MAX - 1 && result == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    rc = del_pos_from_dll(-9999, &list);

#define IS_SUCCESS result == EXIT_SUCCESS && rc == OUT_OF_RANGE
    printf(IS_SUCCESS ? "success\n": "failure\n");
    empty_dll(&list);
    return (IS_SUCCESS);
#undef IS_SUCCESS
}
