# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 11:32:04 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/07 18:46:38 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	fractol

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./includes
LIB_DIR			=	./lib

SYS_CAL			=	-l Xext -l X11 -l m

MLX_DIR			=	./minilibx
MLX_LIB			=	mlx_Linux
MLX_CAL			=	-L ${MLX_DIR} -l ${MLX_LIB}

FT_DIR			=	./libft
FT_LIB			=	ft
FT_CAL			=	-L ${FT_DIR} -l ${FT_LIB}

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -O3
LIBS			=	${MLX_CAL} ${FT_CAL} ${SYS_CAL}
INCS			=	-I ${MLX_DIR} -I ${INC_DIR} -I ${FT_DIR}
SAN				=	-g3 -fsanitize=address

SRCS			=	main.c \
					draw.c \
					ft_mandelbrot.c \
					ft_julia.c \
					ft_burning_ship.c
OBJS			=	${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}

RM				=	rm -rf

DIR_GUARD		=	mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
				${DIR_GUARD}
				${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:		${OBJS}
				make -C ${FT_DIR} all
				make -C ${MLX_DIR} all
				${CC} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

all:			${NAME}

bonus:			${NAME}

san:			${OBJS}
				make -C ${FT_DIR} all
				make -C ${MLX_DIR} all
				${CC} ${SAN} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

clean:
				${RM} ${OBJ_DIR}
				make -C ${MLX_DIR} $@
				make -C ${FT_DIR} $@

fclean: 		clean
				${RM} ${NAME}
				make -C ${FT_DIR} $@

re:				fclean all

.PHONY:			all bonus san clean fclean re

# NAME			=	libfractol.a
# EXEC			=	fractol

# LIBFT			=	libft/libft.a

# MAIN			=	src/main.c
# SRC				=	src/draw.c \
# 					src/fractals.c
# OBJ				=	$(SRC:.c=.o)

# HEADERS			=	-I includes -I minilibx-linux

# CC				=	gcc
# CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3
# MLXFLAGS		=	-Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lbsd -lm

# .DEFAULT_GOAL	=	all

# all:				$(NAME)
# 					$(CC) $(CFLAGS) -o $(EXEC) $(MAIN) $(NAME) $(MLXFLAGS) $(HEADERS) 

# bonus:				$(NAME)

# %.o:				%.c
# 					$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

# $(NAME):			$(LIBFT) $(OBJ)
# 					ar cr $(NAME) $(OBJ)

# $(LIBFT):
# 					make all -C libft
# 					cp $(LIBFT) $(NAME)

# clean:
# 					make clean -C libft
# 					rm -f $(OBJ)

# fclean:				clean
# 					make fclean -C libft
# 					rm -f $(NAME) $(EXEC)

# re:					fclean all

# rebonus:			fclean bonus

# .PHONY:				all bonus libft clean fclean re rebonus
