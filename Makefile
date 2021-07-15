#Compilation

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INC = -I.

#VALUES

NAME	= cub3D
MLX = -lmlx -lm -framework OpenGL -framework AppKit

#SOURCES

FILES	=	ft_checksprite.c		\
			ft_mainLoop2.c		\
			ft_parseMap.c		\
			main.c		\
			ft_chkOrder.c		\
			ft_memcpy.c		\
			loop1.c			\
			ft_parsing.c		\
			ft_createmap.c		\
			ft_move.c	\
			ft_strlen2.c	\
			ft_ceiling.c	\
			ft_init.c			\
			ft_move2.c		\
			ft_write.c		\
			ft_checkMap.c		\
			ft_isalpha.c		\
			ft_paramsprite.c	\
			ft_checkParams.c	\
			ft_isdigit.c		\
			ft_parse.c		\
			ft_checkpos.c		\
			ft_keys.c		\
			ft_parse2.c		\
			loop2.c			\
			get_next_line/get_next_line.c	\
			get_next_line/get_next_line_utils.c	\
			ft_tester.c

OBJS	= ${FILES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
		@cc $(OBJS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
				rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
