/*
 * Name: sll.c
 * Desc:
 *      Implementation of a single-linked list.
*/

#include "../lib/sll.h"

los_t
add_to_sll(const int value, SLL_NODE **head, const int position)
{
    SLL_NODE *new = NULL;
    SLL_NODE *list = *head;

    /* new list to add */
    if ((new = (SLL_NODE*) malloc(sizeof(SLL_NODE))) == NULL)
        return MAKE_LOS_STATE(ERROR, MEMORY_ERROR, "could not allocate memory", NO_RESULT);

    /* copy data */
    new->value = value;

    /* list empty OR front of list */
    if (!list || position == 1)
    {
        new->next = list;
        (*head) = new;

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "added to front", value);
    }

    /* end of list */
    if (position == -1)
        for (; list->next; list = list->next) ;

    /* elsewhere */
    else
        for (int i = 1; i < (position - 1) && list->next; i++, list = list->next) ;

    new->next = list->next;
    list->next = new;

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "added", value);
}


los_t
del_val_from_sll(const int value, SLL_NODE **head)
{
    SLL_NODE *prev = *head;
    SLL_NODE *current = prev->next;

    if (!prev) return MAKE_LOS_STATE(NOERROR, EMPTY, "list empty", NO_RESULT);

    /* delete first node */
    if (prev->value == value)
    {
        *head = prev->next;
        free(prev);

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted", value);
    }

    /* delete any other node */
    for (; current && current->value != value; prev = current, current = (prev ? prev->next : NULL)) ;

    if (!current)
        return MAKE_LOS_STATE(ERROR, NOT_FOUND, "value not found", value);

    prev->next = current->next;
    free(current);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted", value);
}

los_t
del_pos_from_sll(const int position, SLL_NODE **head)
{
    int i = 1;
    SLL_NODE *node = *head;
    SLL_NODE *temp = NULL;
    int deleted;

    if (!node) return MAKE_LOS_STATE(NOERROR, EMPTY, "list empty", NO_RESULT);

    /* delete first node */
    if (position == 1 || (position == -1 && !node->next))
    {
        deleted = node->value;
        (*head) = node->next;
        free(node);

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted first node", deleted);
    }

    /* delete from end of list */
    if (position == -1)
        for (; node->next->next; node = node->next) ;

    /* delete elsewhere */
    else
        for (; i < (position - 1) && node->next; i++, node = node->next) ;

    if (i < position - 1 || position < -1)
        return MAKE_LOS_STATE(ERROR, OUT_OF_RANGE, "position out of range", NO_RESULT);

    deleted = node->next->value;
    temp = node->next;
    node->next = node->next->next;
    free(temp);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted", deleted);
}

los_t
empty_sll(SLL_NODE **head)
{
    los_t result;

    do result = del_pos_from_sll(1, head); while (result.rc != EMPTY);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "list emptied", NO_RESULT);
}

bool
sll_is_empty(SLL_NODE *head)
{
    return !head;
}

void
print_sll(SLL_NODE *list)
{
    if (!list)
    {
        printf("Empty list...\n");
        return;
    }

    SLL_NODE *link = list;

    for (; link; link = link->next)
        printf("%d--->", link->value);
        
    printf("NULL\n");

    return;
}
