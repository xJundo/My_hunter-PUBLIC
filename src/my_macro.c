/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"
#include <SFML/Graphics.h>
#include <stdlib.h>


int on_button(game_info_t *game_info, nodes_t *temp)
{
    button_t *button = temp->data;

    if (MOUSE_POS.x >= button->position.x
        && MOUSE_POS.x <= button->position.x +
        button->rect.width * button->scale.x
        && (MOUSE_POS.y >= button->position.y
        && MOUSE_POS.y <= button->position.y +
        button->rect.height) *button->scale.y) {
        return 1;
    }
    return 0;
}

int on_button_click(game_info_t *game_info, nodes_t *temp)
{
    button_t *button = temp->data;

    if (MOUSE_CLICK.x >= button->position.x
        && MOUSE_CLICK.x <= button->position.x +
        button->rect.width * button->scale.x
        && (MOUSE_CLICK.y >= button->position.y
        && MOUSE_CLICK.y <= button->position.y + button->rect.height)
        * button->scale.y)
        return 1;
    return 0;
}

int left_to_right_hit(game_info_t *game_info, npc_t *current_bird)
{
    if ((MOUSE_CLICK.x >= BIRD_X && MOUSE_CLICK.x <= BIRD_X + BIRD_AREA_X)
        && (MOUSE_CLICK.y >= BIRD_Y && MOUSE_CLICK.y <= BIRD_Y + BIRD_AREA_Y))
        return 1;
    return 0;
}

int right_to_left_hit(game_info_t *game_info, npc_t *current_bird)
{
    if ((MOUSE_CLICK.x >= BIRD_X - BIRD_AREA_X && MOUSE_CLICK.x <= BIRD_X)
        && (MOUSE_CLICK.y >= BIRD_Y && MOUSE_CLICK.y <= BIRD_Y + BIRD_AREA_Y))
        return 1;
    return 0;
}

int sound_not_active(game_info_t *game_info)
{
    if (sfSound_getStatus(game_info->menu->sound_button) != sfPlaying)
        return 1;
    return 0;
}
