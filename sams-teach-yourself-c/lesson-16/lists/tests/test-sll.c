/*
 * Name: sll-test.c
 * Desc:
 *      Test suite for single-linked list.
*/

#include "../lib/sll.h"

#define MAX 11

static bool test_add_to_front(void);
static bool test_add_to_middle(void);
static bool test_add_to_end(void);

static bool test_del_from_front(void);
static bool test_del_from_middle(void);
static bool test_del_from_end(void);
static bool test_del_val(void);
static bool test_del_pos(void);
static bool test_del_nonexistent_val(void);
static bool test_del_nonexistent_pos(void);

/* main */
int
main(void)
{
    if (
        test_add_to_front()         &&
        test_add_to_middle()        &&
        test_add_to_end()           &&
        test_del_from_front()       &&
        test_del_from_middle()      &&
        test_del_from_end()         &&
        test_del_val()              &&
        test_del_pos()              &&
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
    SLL_NODE *list = NULL;
    SLL_NODE *node = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to front...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, 1);

    /* verify each node has correct value */
    for (node = list, i = MAX - 1; node && node->value == i; node = node->next, i--) ;

    bool is_success = (i == 0 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}


static bool
test_add_to_middle(void)
{
    int i = 1;
    SLL_NODE *list = NULL;
    SLL_NODE *node = NULL;
    int expected[] = { 1, 2, 3, 4, 10, 9, 8, 7, 6, 5 };
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to middle...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, (MAX / 2));

    /* verify each node has correct value */
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

    bool is_success = (i == MAX - 1 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_add_to_end(void)
{
    int i = 1;
    SLL_NODE *list = NULL;
    SLL_NODE *node = NULL;
    los_t result = { EXIT_SUCCESS };
    
    printf("%-40s", "TEST: add to end...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    for (node = list, i = 1; node && node->value == i; node = node->next, i++) ;

    /* verify each node has correct value */
    bool is_success = (i == MAX && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_from_front(void)
{
    int i = 1;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from front...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* free memory, this keeps deleting the first node in the list until it is empty */
    empty_sll(&list);

    bool is_success = (sll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    return is_success;
}

static bool
test_del_from_middle(void)
{
    SLL_NODE *list = NULL;
    SLL_NODE *node = NULL;
    int i = 1, expected[] = { 1, 2, 3, 4, 6, 7, 8, 9, 10 };
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from middle...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* free memory for position MAX / 2 on the list */
    result = del_pos_from_sll((MAX / 2), &list);

    /* verify each node has correct value */
    for (node = list, i = 0; node && node->value == expected[i]; node = node->next, i++) ;

    bool is_success = (!node && i == MAX - 2 && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_from_end(void)
{
    int i = 1;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };
    los_t delete = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete from end...");

    /* add nodes to list */
    for (i = 1; i < MAX && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* free memory - delete last node until list is empty */
    do delete = del_pos_from_sll(-1, &list); while (delete.rc != EMPTY);

    bool is_success = (sll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_val(void)
{
    int i = 0;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete val...");

    /* add nodes to list */
    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* free memory for each node by value, in opposite order of how they were added */
    for (i = MAX - 2; i >= 0 && del_val_from_sll(i, &list).rc != EMPTY; i--);

    bool is_success = (sll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory on failure */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_pos(void)
{
    int i = 0;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete pos...");

    /* add nodes to list */
    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* free memory for each node by position, in opposite order of how they were added */
    for (i = MAX - 2; i >= 0 && del_pos_from_sll(1, &list).rc != EMPTY; i--);

    bool is_success = (sll_is_empty(list) && result.rc == EXIT_SUCCESS);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_nonexistent_val(void)
{
    int i = 0;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };
    los_t delete = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete nonexistent val...");

    /* add nodes to list */
    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* try to delete nonexistent value */
    delete = del_val_from_sll(-9999, &list);

    bool is_success = (result.rc == EXIT_SUCCESS && delete.rc == NOT_FOUND);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}

static bool
test_del_nonexistent_pos(void)
{
    int i = 0;
    SLL_NODE *list = NULL;
    los_t result = { EXIT_SUCCESS };
    los_t delete = { EXIT_SUCCESS };

    printf("%-40s", "TEST: delete nonexistent val...");

    /* add nodes to list */
    for (i = 0; i < MAX - 1 && result.rc == EXIT_SUCCESS; i++) result = add_to_sll(i, &list, -1);

    /* try to delete nonexistent position */
    delete = del_pos_from_sll(-9999, &list);

    bool is_success = (result.rc == EXIT_SUCCESS && delete.rc == OUT_OF_RANGE);
    printf(is_success ? "success\n": "failure\n");

    /* free memory */
    empty_sll(&list);

    return is_success;
}
