# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 11:32:04 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/12 09:43:01 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	fractol

SRC				=	./sources
SRCS			=	main.c \
					ft_draw.c \
					ft_calc.c \
					ft_messages.c \
					ft_init.c \
					ft_clear.c \
					ft_move.c

OBJ				=	./objects
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

INC_DIR			=	./includes

SYS_CAL			=	-l Xext -l X11 -l m -l bsd

MLX_DIR			=	./minilibx

MLX_LIB			=	mlx_Linux

MLX_CAL			=	-L $(MLX_DIR) -l $(MLX_LIB)

FT_DIR			=	./libft

FT_LIB			=	ft

FT_CAL			=	-L $(FT_DIR) -l $(FT_LIB)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3

LIBS			=	$(MLX_CAL) $(FT_CAL) $(SYS_CAL)

INCS			=	-I $(MLX_DIR) -I $(INC_DIR) -I $(FT_DIR)/includes

SAN				=	-g3 -fsanitize=address

RM				=	rm -rf

DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				make all -C $(FT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

fsan:			$(OBJS)
				make all -C $(FT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(SAN) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

clean:
				$(RM) $(OBJ)
				make $@ -C $(MLX_DIR)
				make $@ -C $(FT_DIR)

fclean: 		clean
				$(RM) $(NAME)
				make $@ -C $(FT_DIR)

re:				fclean all

.PHONY:			all bonus fsan clean fclean re
