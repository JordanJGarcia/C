#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIST_EMPTY -1
#define VALUE_NOT_FOUND -2
#define OUT_OF_RANGE -3
#define MEMORY_ERROR -4

struct dll_node {
    int value;
    struct dll_node *prev;
    struct dll_node *next;
};

typedef struct dll_node DLL_NODE;

/* manipulate list */
int     add_to_dll(const int value, DLL_NODE **head, int position);
int     del_val_from_dll(const int value, DLL_NODE **head);
int     del_pos_from_dll(const int position, DLL_NODE **head);
void    empty_dll(DLL_NODE **head);
bool    dll_is_empty(DLL_NODE *head);

/* list utilities */
// int*    dll_vals_to_arr(DLL_NODE *head, int * );

/* print list */
void        print_dll(DLL_NODE *head);

#endif
