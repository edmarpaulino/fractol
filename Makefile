# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 11:32:04 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/06 14:55:13 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libfractol.a
EXEC			=	fractol

LIBFT			=	libft/libft.a

MAIN			=	src/main.c
SRC				=	src/draw.c \
					src/fractals.c
OBJ				=	$(SRC:.c=.o)

HEADERS			=	-I includes -I minilibx-linux

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3
MLXFLAGS		=	-L minilibx-linux -l mlx -L /usr/lib -l Xext -l X11 

.DEFAULT_GOAL	=	all

all:				$(NAME)
					$(CC) $(CFLAGS) -o $(EXEC) $(MAIN) $(NAME) $(MLXFLAGS) $(HEADERS) 

bonus:				$(NAME)

%.o:				%.c
					$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME):			$(LIBFT) $(OBJ)
					ar cr $(NAME) $(OBJ)

$(LIBFT):
					make all -C libft
					cp $(LIBFT) $(NAME)

clean:
					make clean -C libft
					rm -f $(OBJ)

fclean:				clean
					make fclean -C libft
					rm -f $(NAME) $(EXEC)

re:					fclean all

rebonus:			fclean bonus

.PHONY:				all bonus libft clean fclean re rebonus
