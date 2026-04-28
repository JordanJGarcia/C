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
    if 
    (
        test_add_to_front()         &&
        test_add_to_middle()        &&
        test_add_to_end()           &&
        test_del_from_front()       &&
        test_del_from_middle()      &&
        test_del_from_end()         &&
        test_del_val()              &&
        test_del_nonexistent_val()  &&
        test_del_nonexistent_pos()
    )
        printf("All tests passed.\n");
    else
        printf("Failure encounted.\n");

    return 0;
}

static bool
test_add_to_front(void)
{
    int i = 1;
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to front...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, 1);
    for (node = list, i = MAX - 1; node && node->value == i; node = node->next, i--) ;

    bool is_success = (i == 0 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}


static bool
test_add_to_middle(void)
{
    int i = 1;
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int expected[] = { 1, 2, 3, 4, 10, 9, 8, 7, 6, 5 };
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to middle...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, (MAX / 2));
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

    bool is_success = (i == MAX - 1 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_add_to_end(void)
{
    int i = 1;
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to end...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    for (node = list, i = 1; node && node->value == i; node = node->next, i++) ;

    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_del_from_front(void)
{
    int i = 1;
    DLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from front...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);

    /* delete nodes from front */
    empty_dll(&list);

    bool is_success = (dll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}

static bool
test_del_from_middle(void)
{
    DLL_NODE *list = NULL;
    DLL_NODE *node = NULL;
    int i = 1, expected[] = { 1, 2, 3, 4, 6, 7, 8, 9, 10 };
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from middle...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    result = del_pos_from_dll((MAX / 2), &list);
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

    bool is_success = (!node && i == MAX - 2 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_del_from_end(void)
{
    int i = 1;
    DLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from end...");

    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    while (del_pos_from_dll(-1, &list).rc != EMPTY) ;

    bool is_success = (dll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_del_val(void)
{
    int i = 0;
    DLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete val...");

    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);
    for (i = MAX - 2; i >= 0 && del_val_from_dll(i, &list).rc != EMPTY; i--);

    bool is_success = (dll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_del_nonexistent_val(void)
{
    int i = 0;
    DLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete nonexistent val...");

    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);

    bool is_success = (result.rc == EXIT_SUCCESS && del_val_from_dll(-9999, &list).rc == NOT_FOUND);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}

static bool
test_del_nonexistent_pos(void)
{
    int i = 0;
    DLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete nonexistent val...");

    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_dll(i, &list, -1);

    bool is_success = (result.rc == EXIT_SUCCESS && del_pos_from_dll(-9999, &list).rc == OUT_OF_RANGE);
    printf(is_success ? "success\n": "failure\n");
    empty_dll(&list);

    return is_success;
}
