/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"

void add_in_list(nodes_t **head, void *data)
{
    nodes_t *new = malloc(sizeof(nodes_t));

    if (new == NULL)
        return;
    new->data = data;
    new->next = *head;
    *head = new;
}

static void fill_list_of_buttons(menu_t *menu, game_info_t *game_info)
{
    button_t *button;

    for (int i = 0; i < 3; i++) {
        if (i == 0)
            button = button_p(game_info);
        if (i == 1)
            button = button_s(game_info);
        if (i == 2)
            button = button_e(game_info);
        add_in_list(&menu->buttons, button);
    }
}

menu_t *init_menu(game_info_t *game_info,
    char const *music, char const *touch_button)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->buttons = NULL;
    menu->music = init_music(music);
    menu->sound_button = init_sound(touch_button);
    menu->mouse_on_button = NULL;
    return menu;
}

void init_info_window(game_info_t *game_info)
{
    game_info->info_window = malloc(sizeof(window_info_t));
    game_info->info_window->sound_on = 1;
    game_info->info_window->video_mode = (sfVideoMode) {1920, 1080, 32};
    game_info->info_window->my_window =
    sfRenderWindow_create(game_info->info_window->video_mode,
    "my_window", sfNone, NULL);
    sfRenderWindow_setPosition(game_info->info_window->my_window,
    (sfVector2i) {0, 0});
    game_info->info_window->f = 60;
    sfRenderWindow_setFramerateLimit(game_info->info_window->my_window,
    game_info->info_window->f);
    game_info->info_window->background_texture =
    sfTexture_createFromFile("./mcb.png", NULL);
    game_info->info_window->background_sprite = sfSprite_create();
    sfSprite_setTexture(game_info->info_window->background_sprite,
    game_info->info_window->background_texture, false);
}

game_info_t init_game(void)
{
    game_info_t game_info = {0};

    init_info_window(&game_info);
    game_info.state = MENU;
    game_info.menu = init_menu(&game_info, "./sot.ogg", "./over_button.wav");
    fill_list_of_buttons(game_info.menu, &game_info);
    game_info.settings = init_settings(&game_info);
    game_info.play_info = malloc(sizeof(play_info_t));
    game_info.play_info->nb_dino = 0;
    game_info.play_info->eric = 0;
    game_info.play_info->level = 0;
    game_info.play_info->trials = 0;
    game_info.play_info->in_game = init_sound("./poney.ogg");
    game_info.play_info->dying = init_sound("./zemmour.wav");
    return game_info;
}

void display_menu(game_info_t *game_info)
{
    if (sfMusic_getStatus(game_info->menu->music) != sfPlaying
        && game_info->info_window->sound_on == 1)
        sfMusic_play(game_info->menu->music);
    if (game_info->info_window->sound_on == 0)
        sfMusic_pause(game_info->menu->music);
    override_color_button(game_info);
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->info_window->background_sprite, NULL);
    for (nodes_t *temp = game_info->menu->buttons;
        temp != NULL; temp = temp->next) {
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        ((button_t *)temp->data)->sprite, NULL);
        sfRenderWindow_drawText(game_info->info_window->my_window,
        ((button_t *)temp->data)->text, NULL);
        analyse_events(game_info, temp->data);
    }
}
