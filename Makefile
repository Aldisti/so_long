# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:19:41 by adi-stef          #+#    #+#              #
#    Updated: 2023/02/27 13:32:57 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= close.c draw.c help.c hooks.c main.c moves.c npc_moves.c sets.c	\
		  win_init.c printf/ft_printf.c printf/ft_puts.c printf/ft_utils.c	\
		  gnl/get_next_line.c gnl/get_next_line_utils.c	\

OBJS	= ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME): ${OBJS}
		make -C ./mlx
		cp ./mlx/libmlx.dylib .
		${CC} ${CFLAGS} ${OBJS} ${MFLAGS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		make clean -C ./mlx

fclean:	clean
		make clean -C ./mlx
		rm -f libmlx.dylib
		${RM} ${NAME}

re:		fclean all
