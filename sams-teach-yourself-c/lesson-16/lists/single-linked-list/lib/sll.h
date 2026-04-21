#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_EMPTY -1
#define VALUE_NOT_FOUND -2
#define OUT_OF_RANGE -3
#define MEMORY_ERROR -4

struct sll_node {
    int value;
    struct sll_node *next;
};

typedef struct sll_node SLL_NODE;

/* manipulate list */
int     add_to_sll(const int value, SLL_NODE **head, int position);
int     del_val_from_sll(const int value, SLL_NODE **head);
int     del_pos_from_sll(const int position, SLL_NODE **head);
void    empty_sll(SLL_NODE **head);
bool    sll_is_empty(SLL_NODE *head);

/* print list */
void    print_sll(SLL_NODE *head);

#endif
