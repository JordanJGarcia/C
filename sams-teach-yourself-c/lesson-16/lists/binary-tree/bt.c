/*
 * Name: bt.c
 * Desc:
 *      Implementation of a binary tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sll.h"

/* globals */
struct data {
    char *value;
    struct data *prev;
    struct data *next;
};

typedef struct data NODE;
typedef NODE *NODEPTR;

#define MAX 5
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* stack prototypes */
bool    push(const int value, int[] stack);
int     pop(int[] stack);
int     peek(int[] stack);
bool    stack_empty(int[] stack);

//int     get_left_height(NODEPTR node);
//int     get_right_height(NODEPTR node);
//bool    is_height_balanced(NODEPTR node);

int     add_bt_node(const char* value, NODEPTR *head, int position);
int     del_bt_node(const char* value, NODEPTR *head); 
void    print_bt(NODEPTR);

/* main */
int
main(void)
{
    NODEPTR head = NULL;

//    int left_height = get_left_height(head);
//    int right_height = get_right_height(head);

    int values[MAX] = { 1, 2, 3, 4, 5 };

    return 0;
}

//int
//get_left_height(NODEPTR node)
//{
//    int height = 0;
//
//    for (; node; node = node->left, height++) ;
//
//    return height;
//}
//
//int
//get_right_height(NODEPTR node)
//{
//    int height = 0;
//
//    for (; node; node = node->right, height++) ;
//
//    return height;
//}

/* position can be:
 *      -1 for end of list, or
 *      numerical position desired in list, if bigger than list size, its placed at the end.
 */
int
add_bt_node(const char *value, NODEPTR *head, int position)
{
    NODEPTR new = NULL;
    NODEPTR link = *head;

    /* new link to add_bt_node */
    if ((new = (NODEPTR) malloc(sizeof(NODE))) == NULL)
    {
        fprintf(stderr, "Could not allocate memory\n");
        return(EXIT_FAILURE);
    }

    /* copy data */
    strcpy(new->value, value);

    /* list empty OR front of list */
    if (!link || position == 1)
    {
        new->next = link;
        (*head) = new;
        return EXIT_SUCCESS;
    }

    /* end of list */
    if (position == -1)
        for (; link->next; link = link->next) ;

    /* elsewhere */
    else
        for (int i = 1; link->next && i < (position - 1); i++, link = link->next) ;

    new->next = link->next;
    link->next = new;

    return EXIT_SUCCESS;
}


int
del_bt_node(const char *value, NODEPTR* head)
{
    NODEPTR prev = *head;
    NODEPTR current = prev->next;

    /* del_bt_node first node */
    if (strcmp(value, prev->value) == 0)
    {
        *head = prev->next;
        return EXIT_SUCCESS;
    }

    /* del_bt_node any other node */
    while (current)
    {
        if (strcmp(value, current->value) == 0)
            break;

        prev = current;
        current = (prev ? prev->next : NULL);
    }

    if (!current)
    {
        fprintf(stderr, "Node not found in list\n");
        return EXIT_SUCCESS;
    }

    prev->next = current->next;
    free(current);

    return EXIT_SUCCESS;
}


void
print_bt(NODEPTR list)
{
    if (!list)
    {
        printf("Empty list...\n");
        return;
    }

    NODEPTR link = list;

    for (; link; link = link->next)
        printf("%s--->", link->value);
        
    printf("NULL\n");

    return;
}
