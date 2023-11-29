/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/csfml.h"

sfText *init_text(text_t info_text)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(info_text.police);

    if (font != NULL)
        sfText_setFont(text, font);
        sfText_setString(text, info_text.str);
        sfText_setCharacterSize(text, info_text.size);
        sfText_setColor(text, info_text.color);
        sfText_setStyle(text, info_text.style);
        sfText_setOutlineColor(text, info_text.outline_color);
        sfText_setOutlineThickness(text, info_text.outline_size);
        sfText_setScale(text, info_text.scale);
        sfText_setPosition(text, info_text.position);
    return text;
}
