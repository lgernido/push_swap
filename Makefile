###########################################################################
#### ARGUMENTS

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDE		= push_swap.h

###########################################################################
#### SOURCES

SRC_FILES = push_swap.c ft_init_stack.c utils.c error_check.c swap.c \
push.c rotate.c reverse_rotate.c sorting.c sorting_null.c

OBJ_FILES = $(SRC_FILES:.c=.o)
###########################################################################
#### RULES

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

all : clean fclean

clean :
	rm -f *.o
	rm -f *.o ${OBJ_FILES}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : bonus all clean fclean re