/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

void draw_menu(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->menu->buttons;
        temp != NULL; temp = temp->next) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((button_t *)temp->data)->sprite, NULL);
        sfRenderWindow_drawText(game_info->info_window->my_window,
        ((button_t *)temp->data)->text, NULL);
        analyse_events(game_info, temp->data);
    }
}

void display_pause(game_info_t *game_info)
{
    sfSound_pause(game_info->play_info->in_game);
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->info_window->background_sprite, NULL);
    override_color_button(game_info);
    display_score(game_info);
    display_life(game_info);
    for (nodes_t *bird = game_info->play_info->birds_list;
        bird != NULL; bird = bird->next) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((npc_t *)bird->data)->sprite, NULL);
    }
    draw_menu(game_info);
    sfRenderWindow_setMouseCursorVisible
    (game_info->info_window->my_window, sfTrue);
}
