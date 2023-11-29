/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

static void condition_over_button(game_info_t *game_info, nodes_t *temp)
{
    if (on_button(game_info, temp)) {
        if (sound_not_active(game_info)
            && game_info->menu->mouse_on_button != temp->data) {
            sfSound_play(game_info->menu->sound_button);
            game_info->menu->mouse_on_button = temp->data;
        }
        if (B_PLAY)
            sfText_setColor(((button_t *)temp->data)->text, sfYellow);
        if (B_SETTINGS)
            sfText_setColor(((button_t *)temp->data)->text, sfYellow);
        if (B_EXIT)
            sfText_setColor(((button_t *)temp->data)->text, sfYellow);
    } else {
        sfText_setColor(((button_t *)temp->data)->text, sfWhite);
        if (game_info->menu->mouse_on_button == temp->data)
            game_info->menu->mouse_on_button = NULL;
    }
}

void override_color_button(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->menu->buttons;
        temp != NULL; temp = temp->next) {
        condition_over_button(game_info, temp);
    }
}

button_t *button_p(game_info_t *game_info)
{
    int x_center_window = (game_info->info_window->video_mode.width / 2
    - (394 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "Play", (sfVector2f) {x_center_window, 300},
    (sfIntRect)  {2048, 260, 394, 153});
    text_t info_text = {.str = "Play", .police = "Skeina.otf", .size = 88,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 7,
    .scale = {1, 1}, .position = {x_center_window + (394 / 2)
    - (my_strlen("Play") / 2 * 38), 310}};

    button->scale = (sfVector2f) {1, 1};
    button->text = init_text(info_text);
    return button;
}

button_t *button_s(game_info_t *game_info)
{
    int x_center_window = (game_info->info_window->video_mode.width / 2 -
    (394 / 2));
    button_t *button =
    init_button(game_info->info_window->background_texture, "Settings",
    (sfVector2f) {x_center_window, 500}, (sfIntRect) {2048, 260, 394, 153});
    text_t info_text = {.str = "Settings", .police = "Skeina.otf", .size = 88,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 7,
    .scale = {1, 1}, .position = {x_center_window + (394 / 2) -
    (my_strlen("Settings") / 2 * 38), 510}};

    button->scale = (sfVector2f) {1, 1};
    button->text = init_text(info_text);
    return button;
}

button_t *button_e(game_info_t *game_info)
{
    int x_center_window = (game_info->info_window->video_mode.width / 2 -
    (394 / 2));
    button_t *button =
    init_button(game_info->info_window->background_texture, "Exit",
    (sfVector2f) {x_center_window, 700}, (sfIntRect) {2048, 260, 394, 153});
    text_t info_text = {.str = "Exit", .police = "Skeina.otf", .size = 88,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 7,
    .scale = {1, 1}, .position = {x_center_window + (394 / 2) -
    (my_strlen("Exit") / 2 * 32), 710}};

    button->scale = (sfVector2f) {1, 1};
    button->text = init_text(info_text);
    return button;
}
