/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

button_t *eric_mode(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (117 * 1 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "ERIC", (sfVector2f) {x_center_window + 165, 230},
    (sfIntRect) {2048, 1152, 117, 162});
    text_t info_text = {.str = "OFF", .police = "Skeina.otf", .size = 50,
            .color = sfWhite, .outline_color = sfBlack, .outline_size = 3,
            .scale = {1, 1}, .position = {x_center_window + 180, 385}};

    button->scale = (sfVector2f) {1, 1};
    button->sound = init_sound("apagnan.ogg");
    button->text = init_text(info_text);
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}

button_t *button_dino(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (327 * 1 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "NB_DINO", (sfVector2f) {x_center_window, 450},
    (sfIntRect) {2054, 655, 327, 42});

    button->scale = (sfVector2f){1, 1};
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}

button_t *surface(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (387 * 1.5 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "Surface", (sfVector2f) {x_center_window, 200},
    (sfIntRect) {2398, 411, 387, 285});

    button->scale = (sfVector2f){1.5, 2};
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}

button_t *sound_icon(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (70 * 1.5 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "SoundIC", (sfVector2f) {x_center_window, 250},
    (sfIntRect) {2462, 842, 70, 72});

    button->scale = (sfVector2f){1.5, 1.5};
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}

button_t *pause_icon(game_info_t *game_info)
{
    int x_center_window =
    (game_info->info_window->video_mode.width / 2 - (70 * 1.5 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "PauseIC", (sfVector2f) {x_center_window - 150, 250},
    (sfIntRect) {2050, 842, 70, 72});

    button->scale = (sfVector2f){1.5, 1.5};
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}
