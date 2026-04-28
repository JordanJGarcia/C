#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./result.h"

struct dll_node {
    int value;
    struct dll_node *prev;
    struct dll_node *next;
};

typedef struct dll_node DLL_NODE;

/* manipulate list */
los_t   add_to_dll(const int value, DLL_NODE **head, int position);
los_t   del_val_from_dll(const int value, DLL_NODE **head);
los_t   del_pos_from_dll(const int position, DLL_NODE **head);
los_t   empty_dll(DLL_NODE **head);
bool    dll_is_empty(DLL_NODE *head);

/* list utilities */
// int*    dll_vals_to_arr(DLL_NODE *head, int * );

/* print list */
void    print_dll(DLL_NODE *head);

#endif
