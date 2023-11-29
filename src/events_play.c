/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include "../include/my.h"
#include "../include/csfml.h"

void hit_condition(game_info_t *game_info, npc_t *current_bird, bool *bird_hit)
{
    if (current_bird->direction.x < 0) {
        if (right_to_left_hit(game_info, current_bird)) {
            current_bird->life = 0;
            sfSound_play(current_bird->hit_sound);
            game_info->play_info->do_score->score += 100;
            *bird_hit = true;
        }
    } else {
        if (left_to_right_hit(game_info, current_bird)) {
            current_bird->life = 0;
            sfSound_play(current_bird->hit_sound);
            game_info->play_info->do_score->score += 100;
            *bird_hit = true;
        }
    }
}

void manage_mouse_click_bird(game_info_t *game_info, npc_t *cur)
{
    bool bird_hit = false;
    npc_t *current_bird;

    for (nodes_t *temp = game_info->play_info->birds_list;
        temp != NULL; temp = temp->next) {
        current_bird = temp->data;
        hit_condition(game_info, current_bird, &bird_hit);
    }
    if (bird_hit == false) {
        sfSound_play(current_bird->miss_sound);
        if (!game_info->play_info->eric)
            game_info->play_info->trials -= 1;
        check_if_trials_decreased(game_info);
    }
}

void manage_touch_in_game(game_info_t *game_info, npc_t *current_bird)
{
    if (game_info->info_window->event.key.code == sfKeyEscape) {
        game_info->state = PAUSE;
    }
}

void state_play(game_info_t *game_info, npc_t *current_bird)
{
    if (game_info->info_window->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click_bird(game_info, current_bird);
    manage_touch_in_game(game_info, current_bird);
}
