/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

button_t *init_button(sfTexture *texture,
    char *text, sfVector2f pos, sfIntRect bite)
{
    button_t *button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    button->text = sfText_create();
    button->rect = bite;
    sfSprite_setTexture(button->sprite, texture, false);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, pos);
    button->position = sfSprite_getPosition(button->sprite);
    button->id = text;
    return button;
}
