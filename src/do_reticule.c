/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"



void move_and_display_reticule(game_info_t *game_info)
{
    sfRenderWindow_setMouseCursorVisible
    (game_info->info_window->my_window, sfFalse);
    sfSprite_setPosition(game_info->crosshair->sprite,
    (sfVector2f){MOUSE_POS.x - (game_info->crosshair->area.width / 2),
    MOUSE_POS.y - (game_info->crosshair->area.height / 2)});
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->crosshair->sprite, NULL);
}

reticule_t *init_crosshair(char const *filename, sfIntRect area)
{
    reticule_t *crosshair = malloc(sizeof(reticule_t));

    crosshair->texture = sfTexture_createFromFile(filename, NULL);
    crosshair->sprite = sfSprite_create();
    crosshair->area = area;
    sfSprite_setTexture(crosshair->sprite, crosshair->texture, false);
    sfSprite_setTextureRect(crosshair->sprite, crosshair->area);
    return crosshair;
}
