/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"

void suite_dino(game_info_t *game_info, nodes_t *temp)
{
    if (game_info->play_info->nb_dino == 3) {
        game_info->play_info->nb_dino = 4;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 464, 327, 42});
        return;
    }
    if (game_info->play_info->nb_dino == 4) {
        game_info->play_info->nb_dino = 5;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 416, 327, 42});
        return;
    }
    if (game_info->play_info->nb_dino == 5) {
        game_info->play_info->nb_dino = 0;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 655, 327, 42});
        return;
    }
    return;
}

void add_dino(game_info_t *game_info, nodes_t *temp)
{
    if (game_info->play_info->nb_dino == 0) {
        game_info->play_info->nb_dino = 1;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 607, 327, 42});
        return;
    }
    if (game_info->play_info->nb_dino == 1) {
        game_info->play_info->nb_dino = 2;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 559, 327, 42});
        return;
    }
    if (game_info->play_info->nb_dino == 2) {
        game_info->play_info->nb_dino = 3;
        sfSprite_setTextureRect
        (((button_t *)temp->data)->sprite, (sfIntRect){2054, 512, 327, 42});
        return;
    }
    suite_dino(game_info, temp);
    return;
}

void switch_to60(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->settings->buttons;
        temp != NULL; temp = temp->next) {
        if (B_30FPS) {
            sfSprite_setTextureRect(((button_t *) temp->data)->sprite,
            (sfIntRect) {2626, 842, 70, 72});
            break;
        }
    }
}

void switch_to30(game_info_t *game_info)
{
    for (nodes_t *temp = game_info->settings->buttons;
        temp != NULL; temp = temp->next) {
        if (B_60FPS) {
            sfSprite_setTextureRect(((button_t *) temp->data)->sprite,
            (sfIntRect) {2626, 842, 70, 72});
            break;
        }
    }
}
