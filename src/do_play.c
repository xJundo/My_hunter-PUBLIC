/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/csfml.h"


void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 2052 + 96;
}

static void spawn_dino(float old_pos, int y,
    game_info_t *game_info, npc_t *current_bird)
{
    if ((old_pos > (float)game_info->info_window->video_mode.width
        || old_pos < 0)) {
        sfSound_play(current_bird->end_window);
        sfSprite_setPosition(current_bird->sprite, rand() % 2 ?
        (sfVector2f) {(float)game_info->info_window->video_mode.width, y} :
        (sfVector2f) {0, y});
        set_bird_pos(game_info, current_bird);
        if (!game_info->play_info->eric)
            game_info->play_info->trials -= 1;
        check_if_trials_decreased(game_info);
    }
    if (current_bird->life == 0) {
        sfSprite_setPosition(current_bird->sprite, rand() % 2 ?
        (sfVector2f) {(float)game_info->info_window->video_mode.width, y} :
        (sfVector2f) {0, y});
        set_bird_pos(game_info, current_bird);
        current_bird->life = 1;
    }
}

void move_sprite(game_info_t *game_info, npc_t *current_bird)
{
    float old_pos = sfSprite_getPosition(current_bird->sprite).x;
    int y = rand() % (game_info->info_window->video_mode.height
    - (current_bird->area.height * 10));

    check_dying(game_info, current_bird, old_pos);
    spawn_dino(old_pos, y, game_info, current_bird);
    sfSprite_move(current_bird->sprite, current_bird->direction);
}

int animation_by_time(game_info_t *game_info, npc_t *current_bird)
{
    sfTime time_bird;
    float seconds_bird;

    game_info->play_info->level =
        (SCORE >= 700) ? 1 : game_info->play_info->level;
    game_info->play_info->level =
        (SCORE >= 2000) ? 2 : game_info->play_info->level;
    game_info->play_info->level =
        (SCORE >= 4000) ? 3 : game_info->play_info->level;
    time_bird = sfClock_getElapsedTime(current_bird->clock);
    seconds_bird = time_bird.microseconds / 1000000.0;
    move_sprite(game_info, current_bird);
    if (seconds_bird > 0.12) {
        move_rect(&(current_bird->area), 24, 2052 + 238);
        sfClock_restart(current_bird->clock);
    }
    return 1;
}

void init_play(game_info_t *game_info)
{
    npc_t *bird;
    int dino = rand() % 2 ? 0 : 17;
    int dino2 = rand() % 2 ? 34 : 51;
    int which_dino = rand() % 2 ? dino : dino2;

    sfSprite_setTextureRect(game_info->info_window->background_sprite,
    (sfIntRect){0, 1152, 1920, 1080});
    game_info->info_window->clock = sfClock_create();
    game_info->crosshair =
    init_crosshair("./crosshair.png", (sfIntRect){0, 0, 150, 150});
    bird = init_bird(game_info->info_window->background_texture,
    (sfIntRect) {2052, which_dino, 15, 17},
    (sfVector2f){game_info->info_window->delay * 300, 0});
    game_info->play_info->birds_list = NULL;
    add_in_list(&game_info->play_info->birds_list, bird);
    game_info->play_info->trials = 3;
    sfRenderWindow_setMouseCursorVisible
    (game_info->info_window->my_window, sfFalse);
    init_score_text(game_info);
}

static void add_by_settings(game_info_t *game_info, npc_t **bird)
{
    int dino;
    int dino2;
    int which_dino;
    int y;

    for (int i = 0; i < game_info->play_info->nb_dino; i++) {
        y = rand() % (game_info->info_window->video_mode.height - (17 * 10));
        dino = (rand() % 2 ? 0 : 17);
        dino2 = (rand() % 2 ? 34 : 51);
        which_dino = rand() % 2 ? dino : dino2;
        *bird = init_bird(game_info->info_window->background_texture,
        (sfIntRect){2052 + 96, which_dino, 15, 17},
        (sfVector2f){(game_info->info_window->delay * 100)
        * ((game_info->play_info->level + 1) * 2), 0});
        sfSprite_setPosition((*bird)->sprite, (sfVector2f) {0, y});
        add_in_list(&game_info->play_info->birds_list, *bird);
    }
}

static void add_by_level(game_info_t *game_info, npc_t **bird,
    int new_level, int old_level)
{
    int dino = (rand() % 2 ? 0 : 17);
    int dino2 = (rand() % 2 ? 34 : 51);
    int which_dino = rand() % 2 ? dino : dino2;

    add_by_settings(game_info, bird);
    if (new_level != old_level) {
        *bird = init_bird(game_info->info_window->background_texture,
        (sfIntRect){2052 + 96, which_dino, 15, 17},
        (sfVector2f){(game_info->info_window->delay * 100)
        * ((game_info->play_info->level + 1) * 2), 0});
        add_in_list(&game_info->play_info->birds_list, *bird);
    }
    game_info->play_info->nb_dino = 0;
}

static void display_bird(game_info_t *game_info, int *new_level)
{
    npc_t *t;

    for (nodes_t *tmp = game_info->play_info->birds_list;
        tmp != NULL; tmp = tmp->next) {
        t = ((npc_t *)tmp->data);
        t->position = sfSprite_getPosition(t->sprite);
        analyse_events(game_info, tmp->data);
        animation_by_time(game_info, tmp->data);
        sfSprite_setTextureRect(t->sprite, t->area);
        sfRenderWindow_drawSprite(game_info->info_window->my_window,
        t->sprite, NULL);
        move_and_display_reticule(game_info);
        *new_level = game_info->play_info->level;
    }
}

void display_play(game_info_t *game_info)
{
    int old_level = game_info->play_info->level;
    npc_t *bird;
    int new_level;

    if (sfSound_getStatus(game_info->play_info->in_game) != sfPlaying
        && game_info->info_window->sound_on)
        sfSound_play(game_info->play_info->in_game);
    sfRenderWindow_drawSprite(game_info->info_window->my_window,
    game_info->info_window->background_sprite, NULL);
    display_score(game_info);
    display_bird(game_info, &new_level);
    add_by_level(game_info, &bird, new_level, old_level);
    if (!game_info->play_info->eric)
        check_life(game_info);
    display_life(game_info);
}
