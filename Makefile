###########################################################################
#### ARGUMENTS

NAME		= 
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE		= push_swap.h
AR 			= ar -rc 

###########################################################################
#### SOURCES

SRC_FILES = push_swap.c ft_init_stack.c

OBJ_FILES = OBJ_FILES	= $(SRC_FILES:.c=.o)
###########################################################################
#### RULES

$(NAME) : ${OBJ_FILES}
		${AR} ${NAME} ${OBJ_FILES}

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I ./ -c $< -o $@

all : clean fclean

clean :
	rm -f *.o
	rm -f *.o ${OBJ_FILES}

fclean : clean
	rm -f ${NAME}

re : fclean ${NAME}

.PHONY : bonus all clean fclean re