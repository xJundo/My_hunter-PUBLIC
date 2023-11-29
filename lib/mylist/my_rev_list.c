/*
** EPITECH PROJECT, 2023
** rev list
** File description:
** reverse order of list elements
*/

#include "mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *rev = NULL;

    while (current != NULL) {
        push_front(&rev, current->data);
        current = current->next;
    }
    *begin = rev;
}

/*void my_rev_list2(linked_list_t **begin)
{
    linked_list_t *prev = NULL;
    linked_list_t *current = *begin;
    linked_list *next = NULL;

    while(current != NULL) {
        prev = current->data;
        next = current->next;
        current = next;
        current->next = prev;
    }

}*/
