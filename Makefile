##
## EPITECH PROJECT, 2020
## make
## File description:
## makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

UTILS	=		./src/utils/free_all.c \
	  			./src/utils/my_printf.c \
	  			./src/utils/my_put_nbr.c \
	  			./src/utils/my_putchar.c \
	  			./src/utils/my_puterror.c \
	  			./src/utils/my_putstr.c \
	  			./src/utils/my_str_isalpha_num.c \
	  			./src/utils/my_str_to_word_array.c \
	  			./src/utils/my_strcat.c \
	  			./src/utils/my_strcat_env.c \
	  			./src/utils/my_strcmp.c \
	  			./src/utils/my_strcpy_n_start.c \
	  			./src/utils/my_strdup.c \
	  			./src/utils/my_strncat.c \
	  			./src/utils/tab_size.c \
				./src/utils/my_char_isalpha.c \


SRCS	= 		./src/get_next_line.c \
	  			./src/main.c \
	  			./src/minishell.c \
				./src/line_formating.c \
	  			./src/my_cd.c \
	  			./src/put_env.c \
	  			./src/set_env.c \
	  			./src/set_path.c \
	  			./src/tild_home.c \
	  			./src/unsetenv.c \
				./src/open_shell.c \
				./src/linked_list.c \
				$(UTILS) \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
