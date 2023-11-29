/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"


button_t *fps_icon30(game_info_t *game_info)
{
    int x_center_window =
            (game_info->info_window->video_mode.width / 2 - (70 * 1.5 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "30FPS", (sfVector2f){x_center_window - 150, 600},
    (sfIntRect) {2626, 842, 70, 73});
    text_t info_text = {.str = "30", .police = "Skeina.otf", .size = 72,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 3,
    .scale = {1, 1}, .position = {x_center_window - 135, 500}};

    button->scale = (sfVector2f){1.5, 1.5};
    sfSprite_setScale(button->sprite, button->scale);
    button->text = init_text(info_text);
    return button;
}

button_t *fps_icon60(game_info_t *game_info)
{
    int x_center_window =
            (game_info->info_window->video_mode.width / 2 - (70 * 1.5 / 2));
    button_t *button = init_button(game_info->info_window->background_texture,
    "60FPS", (sfVector2f){x_center_window + 150, 600},
    (sfIntRect) {2709, 842, 70, 73});
    text_t info_text = {.str = "60", .police = "Skeina.otf", .size = 72,
    .color = sfWhite, .outline_color = sfBlack, .outline_size = 3,
    .scale = {1, 1}, .position = {x_center_window + 165, 500}};

    button->scale = (sfVector2f){1.5, 1.5};
    sfSprite_setScale(button->sprite, button->scale);
    button->text = init_text(info_text);
    return button;
}

void fill_list_of_buttons_settings(menu_t *settings, game_info_t *game_info)
{
    button_t *button;
    button_t *(*create_button[])(game_info_t *) = {&sound_icon, &pause_icon,
    &fps_icon30, &fps_icon60, &button_dino, &eric_mode, &surface};

    for (int i = 0; i < 7; i++) {
        button = create_button[i](game_info);
        add_in_list(&settings->buttons, button);
    }
}

menu_t *init_settings(game_info_t *game_info)
{
    menu_t *settings = init_menu(game_info, "./sot.ogg", "./over_button.wav");

    fill_list_of_buttons_settings(settings, game_info);
    return settings;
}

static void display_bg_settings(game_info_t *game_info)
{
    npc_t *r = NULL;

    if (game_info->old_state == MENU) {
        analyse_events(game_info, r);
    } else {
        display_life(game_info);
        display_score(game_info);
        for (nodes_t *temp = game_info->play_info->birds_list;
            temp != NULL; temp = temp->next) {
            sfRenderWindow_drawSprite(game_info->info_window->my_window,
            ((npc_t *) temp->data)->sprite, NULL);
            analyse_events(game_info, temp->data);
        }
    }
}

void display_settings(game_info_t *game_info)
{
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->info_window->background_sprite, NULL);
    sfRenderWindow_setMouseCursorVisible
    (game_info->info_window->my_window, sfTrue);
    for (nodes_t *temp = game_info->settings->buttons;
        temp != NULL; temp = temp->next) {
        display_bg_settings(game_info);
    }
    for (nodes_t *temp = game_info->settings->buttons;
        temp != NULL; temp = temp->next) {
        sfRenderWindow_drawText(game_info->info_window->my_window,
        ((button_t *) temp->data)->text, NULL);
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((button_t *)temp->data)->sprite, NULL);
    }
}
