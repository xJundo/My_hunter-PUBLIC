##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## The main Makefile of our project
##

CFLAGS = -I./include/ -g3 -Werror -Wpedantic -Wextra
CFLAGS += -lcsfml-graphics -lcsfml-system -lcsfml-audio
LFLAGS = -L./lib -lmylist -lmy
TEST_FLAGS = --coverage -lcriterion -lgcov

SRC	=	src/main.c									\
		src/analyse_events.c						\
		src/do_play.c								\
		src/do_play2.c								\
		src/do_life.c								\
		src/events_play.c							\
		src/do_text.c								\
		src/do_score.c								\
		src/do_menu.c								\
		src/do_menu_buttons.c						\
		src/events_menu.c							\
		src/do_button.c								\
		src/do_sound.c								\
		src/do_reticule.c							\
		src/do_bird.c								\
		src/do_pause.c								\
		src/events_pause.c							\
		src/do_dying.c								\
        src/events_dying.c							\
		src/do_lose.c								\
		src/events_lose.c							\
		src/do_settings.c							\
		src/do_settings_buttons.c					\
		src/events_settings.c						\
		src/events_settings2.c						\
		src/my_getnbr2.c							\
		src/free_all.c								\
		src/my_macro.c								\


OBJ	=	$(SRC:.c=.o)

NAME  = my_hunter

all: libmy libmylist test

libmy:
	make -C ./lib/my/

libmylist:
	make -C ./lib/mylist/

test: $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LFLAGS)

valgrind: $(OBJ)
	@gcc $(OBJ) -g3 $(CFLAGS) $(LFLAGS)
	@valgrind -s ./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

clean_lib:
	@make fclean -C./lib/my/
	@make fclean -C./lib/mylist/
	@make fclean -C./tests/

re:	fclean clean_lib all

unit_tests: re
	make unit_tests -C ./tests/

tests_run: re
	make -C ./tests/
	@gcovr
