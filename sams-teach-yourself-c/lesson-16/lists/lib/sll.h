#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./result.h"

struct sll_node {
    int value;
    struct sll_node *next;
};

typedef struct sll_node SLL_NODE;

/* manipulate list */
los_t   add_to_sll(const int value, SLL_NODE **head, int position);
los_t   del_val_from_sll(const int value, SLL_NODE **head);
los_t   del_pos_from_sll(const int position, SLL_NODE **head);
los_t   empty_sll(SLL_NODE **head);
bool    sll_is_empty(SLL_NODE *head);

/* print list */
void    print_sll(SLL_NODE *head);

#endif
