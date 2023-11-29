/*
** EPITECH PROJECT, 2023
** concat params
** File description:
** concat param
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    int compteur = 0;
    int compteur2 = 0;
    char *str;

    for (int i = 0; i < argc; i ++) {
        compteur += my_strlen(argv[i]);
    }
    str = malloc(sizeof(char) * (compteur + argc));
    for (int i = 0; i < argc; i++) {
        if ( i == argc - 1)
            my_strcat(str, argv[i]);
        else {
        compteur2 += my_strlen(argv[i]);
        my_strcat(str, argv[i]);
        my_strcat(str, "\n");
        }
    }
    return str;
}
