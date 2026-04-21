/*
 * Name: sll.c
 * Desc:
 *      Implementation of a single-linked list.
*/

#include "../lib/sll.h"

/* position can be:
 *      -1 for end of list, or
 *      numerical position desired in list, if bigger than list size, its placed at the end.
 */
int
add_to_sll(const int value, SLL_NODE **head, const int position)
{
    SLL_NODE *new = NULL;
    SLL_NODE *list = *head;

    /* new list to add */
    if ((new = (SLL_NODE*) malloc(sizeof(SLL_NODE))) == NULL)
    {
        fprintf(stderr, "Could not allocate memory\n");
        return(EXIT_FAILURE);
    }

    /* copy data */
    new->value = value;

    /* list empty OR front of list */
    if (!list || position == 1)
    {
        new->next = list;
        (*head) = new;
        return EXIT_SUCCESS;
    }

    /* end of list */
    if (position == -1)
        for (; list->next; list = list->next) ;

    /* elsewhere */
    else
        for (int i = 1; i < (position - 1) && list->next; i++, list = list->next) ;

    new->next = list->next;
    list->next = new;

    return EXIT_SUCCESS;
}


int
del_val_from_sll(const int value, SLL_NODE **head)
{
    SLL_NODE *prev = *head;
    SLL_NODE *current = prev->next;

    if (!prev)
        return LIST_EMPTY;

    /* delete first node */
    if (prev->value == value)
    {
        *head = prev->next;
        free(prev);
        return EXIT_SUCCESS;
    }

    /* delete any other node */
    for (; current && current->value != value; prev = current, current = (prev ? prev->next : NULL)) ;

    if (!current)
        return VALUE_NOT_FOUND;

    prev->next = current->next;
    free(current);

    return EXIT_SUCCESS;
}

int
del_pos_from_sll(const int position, SLL_NODE **head)
{
    int i = 1;
    SLL_NODE *node = *head;
    SLL_NODE *temp = NULL;

    if (!node) return LIST_EMPTY;

    /* delete first node */
    if (position == 1 || (position == -1 && !node->next))
    {
        (*head) = node->next;
        free(node);

        return EXIT_SUCCESS;
    }

    /* delete from end of list */
    if (position == -1)
        for (; node->next->next; node = node->next) ;

    /* delete elsewhere */
    else
        for (; i < (position - 1) && node->next; i++, node = node->next) ;

    if (i < position - 1 || position < -1)
        return OUT_OF_RANGE;

    temp = node->next;
    node->next = node->next->next;
    free(temp);

    return EXIT_SUCCESS;
}

void
empty_sll(SLL_NODE **head)
{
    while (del_pos_from_sll(1, head) != LIST_EMPTY) ;
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
