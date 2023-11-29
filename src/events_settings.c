/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

static int eric_off(game_info_t *game_info, struct nodes *temp)
{
    game_info->play_info->eric = 0;
    if (sfSound_getStatus(((button_t *)temp->data)->sound) != sfPlaying)
        sfSound_play(((button_t *)temp->data)->sound);
    sfText_setString(((button_t *)temp->data)->text, "OFF");
}

static int eric_on(game_info_t *game_info, struct nodes *temp)
{
    if (sfSound_getStatus(((button_t *)temp->data)->sound) != sfPlaying)
        sfSound_play(((button_t *)temp->data)->sound);
    game_info->play_info->eric = 1;
    game_info->play_info->trials = 3;
    sfText_setString(((button_t *)temp->data)->text, "ON");
}

static int button_eric(game_info_t *game_info, struct nodes *temp)
{
    if (on_button_click(game_info, temp) && B_ERIC
        && game_info->play_info->eric == 0) {
        eric_on(game_info, temp);
        if (game_info->old_state != MENU)
            check_if_trials_decreased(game_info);
        return 1;
    }
    if (on_button_click(game_info, temp) && B_ERIC
        && game_info->play_info->eric == 1) {
        eric_off(game_info, temp);
        if (game_info->old_state != MENU)
            check_if_trials_decreased(game_info);
        return 1;
    }
    return 0;
}

static int button_fps(game_info_t *game_info, struct nodes *temp)
{
    if (on_button_click(game_info, temp) && B_30FPS) {
        game_info->info_window->f = 30;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2709, 842, 70, 72});
        switch_to30(game_info);
        return 1;
    }
    if (on_button_click(game_info, temp) && B_60FPS) {
        game_info->info_window->f = 60;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2709, 842, 70, 72});
        switch_to60(game_info);
        return 1;
    }
    return 0;
}

static int button_sound(game_info_t *game_info, nodes_t *temp)
{
    if (on_button_click(game_info, temp) && B_SOUND
        && game_info->info_window->sound_on) {
        game_info->info_window->sound_on = 0;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2545, 842, 70, 72});
        if (game_info->old_state == MENU)
            sfMusic_pause(game_info->menu->music);
        return 1;
    }
    if (on_button_click(game_info, temp) && B_SOUND
        && !game_info->info_window->sound_on) {
        game_info->info_window->sound_on = 1;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2462, 842, 70, 72});
        if (game_info->old_state == MENU)
            sfMusic_play(game_info->menu->music);
        return 1;
    }
    return 0;
}

void manage_click_in_settings(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->settings->buttons;
        temp != NULL; temp = temp->next) {
        if (button_sound(game_info, temp) || button_fps(game_info, temp)
            || button_eric(game_info, temp))
            break;
        if (on_button_click(game_info, temp) && B_PAUSE) {
            game_info->state = game_info->old_state;
            break;
        }
        if (on_button_click(game_info, temp) && B_NB_DINO) {
            add_dino(game_info, temp);
            break;
        }
    }
}

static void reset_sprite_dino(game_info_t *game_info, nodes_t *temp)
{
    if (B_NB_DINO) {
        sfSprite_setTextureRect(((button_t *)temp->data)->sprite,
        (sfIntRect) {2054, 655, 327, 42});
    }
}

void manage_touch_in_settings(game_info_t *game_info)
{
    if (game_info->info_window->event.key.code == sfKeyEscape) {
        game_info->state = game_info->old_state;
        for (nodes_t *temp = game_info->settings->buttons;
            temp != NULL; temp = temp->next) {
            reset_sprite_dino(game_info, temp);
        }
        if (game_info->old_state != MENU)
            check_if_trials_decreased(game_info);
    }
}

void state_settings(game_info_t *game_info, npc_t *current_bird)
{
    manage_click_in_settings(game_info);
    manage_touch_in_settings(game_info);
}
