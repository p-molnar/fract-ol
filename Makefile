# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pmolnar <pmolnar@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/05 16:56:56 by pmolnar       #+#    #+#                  #
#    Updated: 2022/03/01 22:10:04 by pmolnar       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIB_MLX = mlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

NAME = fractol
SRC =	main.c  \
		rendering.c  \
		init.c  \
		colors.c  \
		fractal.c  \
		event_handler.c \

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB_MLX) $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -I$(LIB_MLX) -c $^ -o $@

clean:
	rm -f $(OBJ)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: all
	./$(NAME)

norm:
	norminette $(SRC)

$(LIB_MLX):
	make libmlx.a -C $(LIB_MLX)

.PHONY: $(LIB_MLX) $(NAME) all clean fclean re