/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

void manage_touch_in_dying(game_info_t *game_info, npc_t *current_bird)
{
    if (game_info->info_window->event.key.code == sfKeyEscape) {
        game_info->state = PAUSE;
    }
}

void state_dying(game_info_t *game_info, npc_t *current_bird)
{
    return;
}
