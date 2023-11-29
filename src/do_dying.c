/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

void check_dying(game_info_t *game_info, npc_t *current_bird, float old_pos)
{
    return;
}

void display_dying(game_info_t *game_info)
{
    npc_t *t;

    while (sfSound_getStatus(game_info->play_info->dying) == sfPlaying) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        game_info->info_window->background_sprite, NULL);
        for (nodes_t *tmp = game_info->play_info->birds_list;
            tmp != NULL; tmp = tmp->next) {
            t = ((npc_t *) tmp->data);
            t->position = sfSprite_getPosition(t->sprite);
            analyse_events(game_info, tmp->data);
        }
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        t->sprite, NULL);
        move_and_display_reticule(game_info);
    }
    game_info->state = PLAY;
}
