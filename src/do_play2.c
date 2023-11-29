/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/csfml.h"

void check_life(game_info_t *game_info)
{
    if (game_info->play_info->trials <= 0 ) {
        game_info->state = LOSE;
        init_lose(game_info);
    }
}

void set_bird_pos(game_info_t *game_info, npc_t *current_bird)
{
    if (sfSprite_getPosition(current_bird->sprite).x == 0) {
        sfSprite_setScale(current_bird->sprite, (sfVector2f){10, 10});
        current_bird->direction.x =
        (game_info->info_window->delay * 100) *
        ((game_info->play_info->level + 1) * 2);
    } else {
        current_bird->direction.x =
        (game_info->info_window->delay * 100) * -1 *
        ((game_info->play_info->level + 1) * 2);
        sfSprite_setScale(current_bird->sprite, (sfVector2f){-10, 10});
    }
}

void update_score(score_t *set_score)
{
    if (set_score->old_score != set_score->new_score) {
        if (my_getnbr2(set_score->buffer) < set_score->new_score) {
            fclose(set_score->file);
            set_score->file = fopen("./score.txt", "w+");
            fwrite(my_str_nbr_long_long(set_score->new_score), sizeof(char),
            my_strlen(my_str_nbr_long_long(set_score->new_score)),
            set_score->file);
            fclose(set_score->file);
            set_score->file = fopen("./score.txt", "r");
        }
    }
    fread(set_score->buffer, sizeof(char), 10, set_score->file);
}
