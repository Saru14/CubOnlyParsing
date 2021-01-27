SRCNAME =	srcs/get_next_line/get_next_line.c			\
			srcs/get_next_line/get_next_line_utils.c	\
			srcs/parsing/main.c							\
			srcs/parsing/parsing.c						\
			srcs/parsing/event.c						\
			srcs/parsing/resolution.c					\
			srcs/parsing/sprites_path/obstacle.c		\
			srcs/parsing/sprites_path/sky.c				\
			srcs/parsing/sprites_path/ground.c			\
			srcs/parsing/sprites_path/directions.c		\
			srcs/parsing/map_parsing/map.c				\
			srcs/parsing/map_parsing/verif_map.c		\
			srcs/parsing/free.c							\
			srcs/utils/lib_functions_1.c				\

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

CC		= gcc -g -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I./includes/libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C includes/mlx
		make -C includes/libft
		cp includes/mlx/libmlx.dylib .
		${CC} -o ${NAME} ${OBJS} -L./includes/libft -lft -L. -lmlx -framework OpenGL -framework AppKit

all: 		${NAME}

clean:
			make -C includes/mlx clean
			${RM} ${OBJS} ${NAME}

fclean:		clean
			rm -f libmlx.dylib
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus