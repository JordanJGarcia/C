/*
 * Name: dll.c
 * Desc:
 *      Implementation of a doubly-linked list.
*/

#include "../lib/dll.h"

#define MAX 10

los_t
add_to_dll(const int value, DLL_NODE **head, int position)
{
    DLL_NODE *new = NULL;
    DLL_NODE *link = *head;

    /* new link to add */
    if ((new = (DLL_NODE*) malloc(sizeof(DLL_NODE))) == NULL)
        return MAKE_LOS_STATE(ERROR, MEMORY_ERROR, "could not allocate memory", NO_RESULT);

    /* copy data */
    new->value = value;

    /* list empty OR front of list: add to front of list */
    if (!link || position == 1)
    {
        new->prev = NULL;
        new->next = link;
        (*head) = new;
        if (link) link->prev = new;

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "added to front", value);
    }

    /* add to end of list */
    if (position == -1)
        for (; link->next; link = link->next) ;

    /* add elsewhere */
    else
        for (int i = 1; link->next && i < (position - 1); i++, link = link->next) ;

    new->prev = link;
    new->next = link->next;
    if (link->next) link->next->prev = new;
    link->next = new;

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "added", value);
}


los_t
del_val_from_dll(const int value, DLL_NODE **head)
{
    DLL_NODE *node = *head;
    DLL_NODE *next = node->next;

    if (!node) return MAKE_LOS_STATE(NOERROR, EMPTY, "list empty", NO_RESULT);

    /* delete first node */
    if (value == node->value)
    {
        (*head) = node->next;
        if (*head) (*head)->prev = NULL;
        free(node);

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted first node", value);
    }

    /* delete any other node */
    for (; next && next->value != value; node = next, next = (node ? node->next : NULL)) ;

    if (!next)
        return MAKE_LOS_STATE(ERROR, NOT_FOUND, "value not found", value);

    if (next->next) next->next->prev = node;
    node->next = next->next;
    free(next);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted", value);
}


los_t
del_pos_from_dll(const int position, DLL_NODE **head)
{
    int i = 1;
    DLL_NODE *node = *head;
    int deleted;

    if (!node) return MAKE_LOS_STATE(NOERROR, EMPTY, "list empty", NO_RESULT);

    /* delete first node */
    if (position == 1 || (position == -1 && !node->next))
    {
        deleted = node->value;
        (*head) = node->next;
        if(*head) (*head)->prev = NULL;
        free(node);

        return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted first node", deleted);
    }

    /* delete from end of list */
    if (position == -1)
        for (; node->next; node = node->next) ;

    /* delete elsewhere */
    else
        for (; node->next && i < position; i++, node = node->next) ;

    if (i < position || position < -1)
        return MAKE_LOS_STATE(ERROR, OUT_OF_RANGE, "position out of range", NO_RESULT);

    deleted = node->value;
    if (node->next) node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "deleted", deleted);
}

los_t
empty_dll(DLL_NODE **head)
{
    los_t result;

    do result = del_pos_from_dll(1, head); while (result.rc != EMPTY);

    return MAKE_LOS_STATE(NOERROR, EXIT_SUCCESS, "list emptied", NO_RESULT);
}

bool
dll_is_empty(DLL_NODE *head)
{
    return !head;
}

void
print_dll(DLL_NODE *head)
{
    printf("\n%-20s%-20s%-20s\n", "PREV", "VALUE", "NEXT");
    printf("**********************************************************************\n");

    if (!head)
    {
        printf("Empty list...\n");
        printf("**********************************************************************\n");

        return;
    }

    DLL_NODE *link = head;

    for (; link; link = link->next)
    {
        if (link->prev)
            printf("%-20d", link->prev->value);
        else
            printf("%-20p", link->prev);

        printf("%-20d", link->value);

        if (link->next)
            printf("%-20d\n", link->next->value);
        else
            printf("%-20p\n", link->next);
    }
        
    printf("**********************************************************************\n");

    return;
}
