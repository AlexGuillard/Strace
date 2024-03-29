##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD04am-alexandre.guillard
## File description:
## Makefile
##

####### SOURCE #######

MAIN 		=	main.c

SRC			=	source/option_handling.c		\
				source/strace.c 	\
				source/core_pid.c 	\
				source/display_info_string.c	\
				source/core_command.c		\
				source/detect_fonction.c	\
				source/display_info_hexa.c	\
				source/handle_first_args.c 	\
				source/handle_last_args.c	\
				source/handle_display_string.c \
				source/Utils/my_strcat.c	\
				source/Utils/my_str_to_word_array.c

OBJ_MAIN 	=	$(MAIN:%.c=%.o)

OBJ_SRC 	=	$(SRC:%.c=%.o)

####### FLAGS ########

CFLAGS 	=	-std=gnu17 -Wall -Wextra -Iinclude

###### NAME ########

NAME 	= 	strace

###### COMPIL ######

CC		=	gcc

###### RULES #######

all: $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ_SRC) -o $(NAME)

tests_run: $(NAME)

clean:
	rm -f $(OBJ_SRC)
	rm -f $(OBJ_MAIN)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)

# rule only to use debug tools
debug: CFLAGS += -g
debug: re

re: fclean all

# to protect rules
.PHONY: all clean fclean re debug
