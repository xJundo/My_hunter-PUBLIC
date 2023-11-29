/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

static button_t *life_third(game_info_t *game_info)
{
    int y = game_info->info_window->video_mode.height * 1.00 - (157 * 0.5);
    button_t *life = init_button(game_info->info_window->background_texture,
    "life3", (sfVector2f){100, y}, (sfIntRect) {2186, 1159, 182, 157});

    life->scale = (sfVector2f){0.5, 0.5};
    sfSprite_setScale(life->sprite, life->scale);
    return life;
}

static button_t *life_second(game_info_t *game_info)
{
    int y = game_info->info_window->video_mode.height * 1.00 - (157 * 0.5);
    button_t *life = init_button(game_info->info_window->background_texture,
    "life2", (sfVector2f){50, y}, (sfIntRect) {2186, 1159, 182, 157});

    life->scale = (sfVector2f){0.5, 0.5};
    sfSprite_setScale(life->sprite, life->scale);
    return life;
}

static button_t *life_first(game_info_t *game_info)
{
    int y = game_info->info_window->video_mode.height * 1.00 - (157 * 0.5);
    button_t *life = init_button(game_info->info_window->background_texture,
    "life1", (sfVector2f){0, y}, (sfIntRect) {2186, 1159, 182, 157});

    life->scale = (sfVector2f){0.50, 0.50};
    sfSprite_setScale(life->sprite, life->scale);
    return life;
}

void init_life_sprites(game_info_t *game_info)
{
    button_t *(*create_life_sprite[])(game_info_t *) =
    {&life_first, &life_second, &life_third};
    button_t *life;

    game_info->play_info->life_sprites = NULL;
    for (int i = 2; i >= 0; i--) {
        life = create_life_sprite[i](game_info);
        add_in_list(&game_info->play_info->life_sprites, life);
    }
}

void change_rect_by_id(game_info_t *game_info, nodes_t **head, char const *id,
    sfIntRect rect)
{
    nodes_t *list = *head;

    for (nodes_t *temp = list; temp != NULL; temp = temp->next) {
        if (my_strcmp(((button_t *)temp->data)->id, id) == 0)
            sfSprite_setTextureRect(((button_t *)temp->data)->sprite,
            rect);
    }
}

void check_if_trials_decreased(game_info_t *game_info)
{
    sfIntRect alive = {2186, 1159, 182, 157};
    sfIntRect dead = {2382, 1159, 182, 157};
    nodes_t **lifes = &game_info->play_info->life_sprites;

    if (game_info->play_info->trials == 3) {
        change_rect_by_id(game_info, lifes, "life1", alive);
        change_rect_by_id(game_info, lifes, "life2", alive);
        change_rect_by_id(game_info, lifes, "life3", alive);
    }
    if (game_info->play_info->trials == 2) {
        change_rect_by_id(game_info, lifes, "life3", dead);
    }
    if (game_info->play_info->trials == 1) {
        change_rect_by_id(game_info, lifes, "life2", dead);
    }
    if (game_info->play_info->trials == 0) {
        change_rect_by_id(game_info, lifes, "life1", dead);
    }
}

void display_life(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->play_info->life_sprites;
        temp != NULL; temp = temp->next) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((button_t *)temp->data)->sprite, NULL);
    }
}
