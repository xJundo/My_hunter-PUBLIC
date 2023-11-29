/*
** EPITECH PROJECT, 2023
** my show list
** File description:
** print a list
*/

#include "mylist.h"
#include <stddef.h>
#include <stdio.h>

int my_show_list(linked_list_t *liste)
{
    linked_list_t *copy = liste;
    int compteur = 0;

    for (; copy->data != NULL; copy = copy->next) {
        printf("%d", copy->data);
        compteur++;
    }
    return compteur;
}
