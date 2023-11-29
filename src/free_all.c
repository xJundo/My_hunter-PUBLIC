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

static void free_score(game_info_t *game_info)
{
    free(game_info->play_info->do_score->buffer);
    sfText_destroy(game_info->play_info->do_score->text_sc);
    sfText_destroy(game_info->play_info->do_score->text_sc_nb);
    sfText_destroy(game_info->play_info->do_score->text_record);
    sfText_destroy(game_info->play_info->do_score->text_record_nb);
    sfFont_destroy(game_info->play_info->do_score->font);
    fclose(game_info->play_info->do_score->file);
}

static void free_bird(game_info_t *game_info)
{
    nodes_t *temp = game_info->play_info->birds_list;
    nodes_t *previous;

    while (temp != NULL) {
        previous = temp;
        sfClock_destroy(((npc_t *)previous->data)->clock);
        sfSound_destroy(((npc_t *)previous->data)->hit_sound);
        sfSound_destroy(((npc_t *)previous->data)->miss_sound);
        sfSound_destroy(((npc_t *)previous->data)->end_window);
        sfSprite_destroy(((npc_t *)previous->data)->sprite);
        temp = temp->next;
        free(previous);
    }
    return;
}

static void free_menu(game_info_t *game_info)
{
    nodes_t *temp = game_info->menu->buttons;
    nodes_t *previous;

    while (temp != NULL) {
        previous = temp;
        sfText_destroy(((button_t *)previous->data)->text);
        sfSprite_destroy(((button_t *)previous->data)->sprite);
        sfTexture_destroy(((button_t *)previous->data)->texture);
        sfSound_destroy(((button_t *)previous->data)->sound);
        free(((button_t *)previous->data)->id);
        temp = temp->next;
        free(previous);
    }
    sfMusic_destroy(game_info->menu->music);
    sfSound_destroy(game_info->menu->sound_button);
    sfSound_destroy(game_info->menu->sound_button);
    free(game_info->menu->buttons);
    free(game_info->menu);
}

static void free_settings(game_info_t *game_info)
{
    nodes_t *temp = game_info->settings->buttons;
    nodes_t *previous;

    while (temp != NULL) {
        previous = temp;
        sfText_destroy(((button_t *)previous->data)->text);
        sfSprite_destroy(((button_t *)previous->data)->sprite);
        sfTexture_destroy(((button_t *)previous->data)->texture);
        sfSound_destroy(((button_t *)previous->data)->sound);
        free(((button_t *)previous->data)->id);
        temp = temp->next;
        free(previous);
    }
    sfMusic_destroy(game_info->settings->music);
    sfSound_destroy(game_info->settings->sound_button);
    sfSound_destroy(game_info->settings->sound_button);
    free(game_info->settings->buttons);
    free(game_info->settings);
}

void free_window(game_info_t *game_info)
{
    sfTexture_destroy(game_info->info_window->background_texture);
    sfSprite_destroy(game_info->info_window->background_sprite);
}

void state_free_all(game_info_t *game_info, npc_t *current)
{
    if (game_info->old_state == MENU
        || game_info->old_state == PAUSE
        || game_info->old_state == LOSE) {
        free_menu(game_info);
        free_settings(game_info);
    }
    if (game_info->old_state == PAUSE || game_info->old_state == LOSE) {
        free_settings(game_info);
        free_bird(game_info);
        free_score(game_info);
    }
    return;
}

void display_free_all(game_info_t *game_info)
{
    return;
}
