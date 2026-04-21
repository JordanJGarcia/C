/*
 * Name: dll.c
 * Desc:
 *      Implementation of a doubly-linked list.
*/

#include "../lib/dll.h"

#define MAX 10

/* 
 * position can be:
 *      -1 for end of list, or
 *      numerical position desired in list, if bigger than list size, its placed at the end.
*/
int
add_to_dll(const int value, DLL_NODE **head, int position)
{
    DLL_NODE *new = NULL;
    DLL_NODE *link = *head;

    /* new link to add */
    if ((new = (DLL_NODE*) malloc(sizeof(DLL_NODE))) == NULL)
    {
        fprintf(stderr, "Could not allocate memory\n");
        return MEMORY_ERROR;
    }

    /* copy data */
    new->value = value;

    /* list empty OR front of list: add to front of list */
    if (!link || position == 1)
    {
        new->prev = NULL;
        new->next = link;
        (*head) = new;
        if (link) link->prev = new;

        return EXIT_SUCCESS;
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

    return EXIT_SUCCESS;
}


int
del_val_from_dll(const int value, DLL_NODE **head)
{
    DLL_NODE *node = *head;
    DLL_NODE *next = node->next;

    if (!node) return LIST_EMPTY;

    /* delete first node */
    if (value == node->value)
    {
        (*head) = node->next;
        if (*head) (*head)->prev = NULL;
        free(node);

        return EXIT_SUCCESS;
    }

    /* delete any other node */
    for (; next && next->value != value; node = next, next = (node ? node->next : NULL)) ;

    if (!next)
        return VALUE_NOT_FOUND;

    if (next->next) next->next->prev = node;
    node->next = next->next;
    free(next);

    return EXIT_SUCCESS;
}


int
del_pos_from_dll(const int position, DLL_NODE **head)
{
    int i = 1;
    DLL_NODE *node = *head;

    if (!node) return LIST_EMPTY;

    /* delete first node */
    if (position == 1 || (position == -1 && !node->next))
    {
        (*head) = node->next;
        if(*head) (*head)->prev = NULL;
        free(node);

        return EXIT_SUCCESS;
    }

    /* delete from end of list */
    if (position == -1)
        for (; node->next; node = node->next) ;

    /* delete elsewhere */
    else
        for (; node->next && i < position; i++, node = node->next) ;

    if (i < position || position < -1)
        return OUT_OF_RANGE;

    if (node->next) node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);

    return EXIT_SUCCESS;
}

void
empty_dll(DLL_NODE **head)
{
    while (del_pos_from_dll(1, head) != LIST_EMPTY) ;
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
