/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

sfMusic *init_music(char const *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    sfMusic_setLoop(music, sfTrue);
    return music;
}

sfSound *init_sound(char const *filename)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filename);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    return sound;
}
