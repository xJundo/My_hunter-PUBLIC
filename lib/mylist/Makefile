##
## EPITECH PROJECT, 2023
## starting with makefile
## File description:
## starting with makefile
##

CFLAGS = -Werror -Wpedantic

SRC	=	my_params_to_list.c	\
		my_list_size.c		\
		my_rev_list.c		\
		my_show_list.c		\
		my_apply_on_nodes.c	\
		my_apply_on_matching_nodes.c \
		my_find_node.c 		\
		my_delete_nodes.c	\
		my_concat_list.c	\
		my_sort_list.c		\
		my_strput.c		\
		my_charput.c		\
		my_nbr_put.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmylist.a

all: $(NAME)

$(NAME): $(OBJ)
	echo lib of linked list
	cp mylist.h ../../include
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
