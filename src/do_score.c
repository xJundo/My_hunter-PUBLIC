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

void display_score(game_info_t *game_info)
{
    sfText_setString(SCORE_NB, my_str_nbr_long_long(SCORE));
    sfRenderWindow_drawText
    (game_info->info_window->my_window, SCORE_TEXT, NULL);
    sfRenderWindow_drawText
    (game_info->info_window->my_window, SCORE_NB, NULL);
    sfRenderWindow_drawText
    (game_info->info_window->my_window, RECORD_TEXT, NULL);
    if (RECORD < SCORE)
        sfText_setString(RECORD_NB, my_str_nbr_long_long(SCORE));
    sfRenderWindow_drawText
    (game_info->info_window->my_window, RECORD_NB, NULL);
}

void init_score_text(game_info_t *game_info)
{
    int x = game_info->info_window->video_mode.width - 200;
    int y = game_info->info_window->video_mode.height - 200;
    text_t info_text = {.str = "SCORE : ", .police = "Skeina.otf", .size = 40,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 3,
    .scale = {1, 1}, .position = {x - 200, y}};

    SCORE_TEXT = init_text(info_text);
    info_text = (text_t) {.str = my_str_nbr_long_long(SCORE),
    .police = "Skeina.otf", .size = 50, .color = sfWhite,
    .outline_color = sfBlack, .outline_size = 3,
    .scale = {1, 1}, .position = {x, y - 10}};
    SCORE_NB = init_text(info_text);
    info_text = (text_t) {.str = "Record : ", .police = "Skeina.otf",
    .size = 40, .color = sfWhite, .outline_color = sfBlack, .outline_size = 3,
    .scale = {1, 1}, .position = {x - 200, y + 100}};
    RECORD_TEXT = init_text(info_text);
    info_text = (text_t) {.str = my_str_nbr_long_long(RECORD),
    .police = "Skeina.otf", .size = 50, .color = sfWhite, .outline_color =
    sfBlack, .outline_size = 3, .scale = {1, 1}, .position = {x, y + 90}};
    RECORD_NB = init_text(info_text);
}
