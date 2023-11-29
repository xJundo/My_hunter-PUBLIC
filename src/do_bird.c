/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

npc_t *init_bird(sfTexture *texture, sfIntRect area, sfVector2f speed)
{
    npc_t *bird = malloc(sizeof(npc_t));

    bird->sprite = sfSprite_create();
    bird->area = area;
    bird->clock = sfClock_create();
    bird->direction = speed;
    bird->hit_sound = init_sound("./roblox.wav");
    bird->miss_sound = init_sound("./fart.wav");
    bird->end_window = init_sound("./zemmour.wav");
    bird->life = 1;
    sfSprite_setTexture(bird->sprite, texture, false);
    sfSprite_setScale(bird->sprite, (sfVector2f){10, 10});
    return bird;
}
