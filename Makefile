###########################################################################
#### ARGUMENTS

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDE		= push_swap.h
ARG			= $(filter-out $@,$(MAKECMDGOALS))

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
RESET=\033[0m

###########################################################################
#### SOURCES

SRC_FILES = push_swap.c ft_init_stack.c utils.c error_check.c swap.c \
push.c rotate.c reverse_rotate.c sorting.c init_nodes.c prepare_push.c \
ft_split.c init_nodes_b.c

OBJ_FILES = $(SRC_FILES:.c=.o)
###########################################################################
#### RULES

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "$(MAGENTA)Les fichiers modifiés sont: $?$(RESET)"
	@echo "$(GREEN)Compilation réussie !$(RESET)"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@
	@echo "$(YELLOW)Compilation de $*$(RESET)"

all : $(NAME)

clean :
	@rm -f *.o
	@rm -f *.o ${OBJ_FILES}
	@echo "$(CYAN) Nettoyage des fichiers intermédiaires $(RESET)"

fclean : clean
	@rm -f ${NAME}
	@echo "$(GREEN) Nettoyage terminé $(RESET)"

re : fclean ${NAME}

test :		$(NAME)
			$(eval ARG = $(shell shuf -i 0-5000 -n $(ARG)))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "$(BLUE)Instructions: "
			@./push_swap $(ARG) | wc -l

.PHONY : bonus all clean fclean re test