/*
** EPITECH PROJECT, 2023
** handle
** File description:
** stop window from crashing
*/

#include <SFML/Graphics.h>
#include "../include/my.h"
#include "../include/csfml.h"


void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void analyse_events(game_info_t *game_info, npc_t *current_bird)
{
    void (*manage_evt_state[])(game_info_t *, npc_t *) = {&state_menu,
        &state_play, &state_pause, &state_lose, &state_dying, &state_settings,
        &state_free_all};

    while (sfRenderWindow_pollEvent(game_info->info_window->my_window,
        &game_info->info_window->event)) {
        if (game_info->info_window->event.type == sfEvtClosed) {
            close_window(game_info->info_window->my_window);
        }
        if (game_info->info_window->event.type == sfEvtMouseButtonPressed) {
            manage_evt_state[game_info->state](game_info, current_bird);
        }
        if (game_info->info_window->event.type == sfEvtKeyPressed) {
            manage_evt_state[game_info->state](game_info, current_bird);
        }
    }
}
