##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD04am-alexandre.guillard
## File description:
## Makefile
##

####### SOURCE #######

MAIN 		=	main.c

SRC			=

OBJ_MAIN 	=	$(MAIN:%.c=%.o)

OBJ_SRC 	=	$(SRC:%.c=%.o)

####### FLAGS ########

CFLAGS 	=	-std=gnu17 -Wall -Wextra -O2 -Iinclude

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
debug: $(BINARY_NAME)

re: fclean all

# to protect rules
.PHONY: all clean fclean re debug
