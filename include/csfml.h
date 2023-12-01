/*
** EPITECH PROJECT, 2023
** Libmy
** File description:
** Store libmy functions prototypes
*/


#ifndef MY_HUNTER_CSFML_H
    #define MY_HUNTER_CSFML_H

    #include <SFML/Graphics.h>

    #define B_PLAY my_strcmp(((button_t *)temp->data)->id, "Play") == 0
    #define B_SETTINGS my_strcmp(((button_t *)temp->data)->id, "Settings") == 0
    #define B_EXIT my_strcmp(((button_t *)temp->data)->id, "Exit") == 0
    #define B_SOUND my_strcmp(((button_t *)temp->data)->id, "SoundIC") == 0
    #define B_PAUSE my_strcmp(((button_t *)temp->data)->id, "PauseIC") == 0
    #define B_30FPS my_strcmp(((button_t *)temp->data)->id, "30FPS") == 0
    #define B_60FPS my_strcmp(((button_t *)temp->data)->id, "60FPS") == 0
    #define B_NB_DINO my_strcmp(((button_t *)temp->data)->id, "NB_DINO") == 0
    #define B_ERIC my_strcmp(((button_t *)temp->data)->id, "ERIC") == 0
    #define B_R my_strcmp(((button_t *)temp->data)->id, "Restart") == 0
    #define B_E my_strcmp(((button_t *)temp->data)->id, "Exit") == 0

    #define BIRD_X current_bird->position.x
    #define BIRD_Y current_bird->position.y
    #define BIRD_AREA_X current_bird->area.width * 10
    #define BIRD_AREA_Y current_bird->area.height * 10

    #define MOUSE_POS game_info->mouse_pos
    #define MOUSE_CLICK game_info->info_window->event.mouseButton

    #define RECORD game_info->play_info->do_score->record
    #define RECORD_NB game_info->play_info->do_score->text_record_nb
    #define RECORD_TEXT game_info->play_info->do_score->text_record

    #define SCORE game_info->play_info->do_score->score
    #define SCORE_NB game_info->play_info->do_score->text_sc_nb
    #define SCORE_TEXT game_info->play_info->do_score->text_sc

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <malloc.h>
    #include <stdlib.h>
    #include <time.h>
    #include <sys/stat.h>

int my_getnbr2(char const *str);

enum scene {
    MENU,
    PLAY,
    PAUSE,
    LOSE,
    DYING,
    SETTINGS,
    FREE_ALL,
};

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfSound *sound;
    char *id;
} button_t;

typedef struct nodes {
    void *data;
    struct nodes *next;
} nodes_t;

typedef struct {
    button_t *mouse_on_button;
    sfMusic *music;
    sfSound *sound_button;
    nodes_t *buttons;
} menu_t;

typedef struct {
    sfVector2f position;
    sfVector2f direction;
    sfIntRect area;
    sfSprite *sprite;
    sfClock *clock;
    sfSound *hit_sound;
    sfSound *miss_sound;
    sfSound *end_window;
    int one_bird_hit;
    int life;
} npc_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect area;
} reticule_t;

typedef struct {
    char const *str;
    sfFont *font;

    char const *police;
    sfColor color;
    int size;

    sfColor outline_color;
    float outline_size;

    sfTextStyle style;

    sfVector2f scale;
    sfVector2f position;
} text_t;

typedef struct {
    FILE *file;
    char *buffer;
    long long int old_score;
    long long int new_score;
    long long int score;
    sfText *text_sc;
    sfText *text_sc_nb;
    sfText *text_record;
    sfText *text_record_nb;
    sfFont *font;
    long long int record;
    long long int old_record;
}score_t;

typedef struct {
    sfVideoMode video_mode;
    sfRenderWindow *my_window;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfClock *clock;
    sfEvent event;
    float resize;
    int f;
    float delay;
    int sound_on;
} window_info_t;

typedef struct playing {
    nodes_t *birds_list;
    score_t *do_score;
    sfSound *in_game;
    sfSound *dying;
    int nb_dino;
    int eric;
    int trials;
    int level;
    nodes_t *life_sprites;
} play_info_t;

typedef struct {
    window_info_t *info_window;
    menu_t *menu;
    menu_t *settings;
    menu_t *exit;
    reticule_t *crosshair;
    struct playing *play_info;
    sfVector2i mouse_pos;
    int state;
    int old_state;
} game_info_t;

void analyse_events(game_info_t *game_info, npc_t *current_bird);
void manage_mouse_click_bird(game_info_t *, npc_t *);
void close_window(sfRenderWindow *window);
void free_window(game_info_t *);
void state_free_all(game_info_t *game_info, npc_t *);
void display_free_all(game_info_t *game_info);


//My Macro
int on_button(game_info_t *game_info, nodes_t *temp);
int on_button_click(game_info_t *game_info, nodes_t *temp);
int left_to_right_hit(game_info_t *game_info, npc_t *current_bird);
int right_to_left_hit(game_info_t *game_info, npc_t *current_bird);
int sound_not_active(game_info_t *game_info);

//Menu
game_info_t init_game(void);
menu_t *init_menu(game_info_t *game_info, char const *, char const *);
void add_in_list(nodes_t **head, void *data);
void display_menu(game_info_t *);
void override_color_button(game_info_t *game_info);
void change_state(game_info_t *game_info);
void state_menu(game_info_t *game_info, npc_t *current_bird);
button_t *button_p(game_info_t *game_info);
button_t *button_s(game_info_t *game_info);
button_t *button_e(game_info_t *game_info);

//Main game
void init_play(game_info_t *);
void display_play(game_info_t *);
int animation_by_time(game_info_t *game_info, npc_t *);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_sprite(game_info_t *game_info, npc_t *);
void set_bird_pos(game_info_t *game_info, npc_t *current_bird);
void update_score(score_t *set_score);
void display_score(game_info_t *);
void set_move_from_time(game_info_t *game_info, npc_t *current_bird);

void hit_condition(game_info_t *game_info, npc_t *current_bird,
    bool *bird_hit);
void manage_mouse_click_bird(game_info_t *game_info, npc_t *cur);
void manage_touch_in_game(game_info_t *game_info, npc_t *current_bird);
void state_play(game_info_t *game_info, npc_t *current_bird);
void check_life(game_info_t *game_info);

void init_life_sprites(game_info_t *);
void display_life(game_info_t *game_info);
void change_rect_by_id(game_info_t *game_info, nodes_t **head, char const *id,
    sfIntRect rect);
void check_if_trials_decreased(game_info_t *);

//Dying
void state_dying(game_info_t *game_info, npc_t *current_bird);
void display_dying(game_info_t *game_info);
void check_dying(game_info_t *game_info, npc_t *current_bird, float old_pos);


//Pause menu
void display_pause(game_info_t *game_info);
void manage_touch_in_pause(game_info_t *game_info);
void state_pause(game_info_t *game_info, npc_t *current_bird);

//Settings menu
menu_t *init_settings(game_info_t *game_info);
void display_settings(game_info_t *game_info);
void state_settings(game_info_t *game_info, npc_t *current_bird);
void add_dino(game_info_t *game_info, nodes_t *temp);
void suite_dino(game_info_t *game_info, nodes_t *temp);
void switch_to60(game_info_t *game_info);
void switch_to30(game_info_t *game_info);
void manage_click_in_settings(game_info_t *game_info);
void fill_list_of_buttons_settings(menu_t *settings, game_info_t *game_info);
button_t *fps_icon30(game_info_t *game_info);
button_t *fps_icon60(game_info_t *game_info);
button_t *pause_icon(game_info_t *game_info);
button_t *sound_icon(game_info_t *game_info);
button_t *surface(game_info_t *game_info);
button_t *button_dino(game_info_t *game_info);
button_t *eric_mode(game_info_t *game_info);


//Lose menu
void init_lose(game_info_t *game_info);
void display_lose(game_info_t *game_info);
void state_lose(game_info_t *game_info, npc_t *current_bird);


//Bird creation
npc_t *init_bird(sfTexture *texture, sfIntRect area, sfVector2f speed);

//Text set
void init_score_text(game_info_t *game_info);
sfText *set_text(char const *str, char  const *font, int size);
sfText *init_text(text_t info_text);

//Button creation
button_t *init_button(sfTexture *, char *text, sfVector2f pos, sfIntRect area);

//Sound creation
sfSound *init_sound(char const *filename);
sfMusic *init_music(char const *filename);

//Reticule creation APAGNAN
reticule_t *init_crosshair(char const *filename, sfIntRect area);
void move_and_display_reticule(game_info_t *);



#endif //MY_HUNTER_CSFML_H
