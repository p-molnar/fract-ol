# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pmolnar <pmolnar@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/05 16:56:56 by pmolnar       #+#    #+#                  #
#    Updated: 2022/03/08 15:17:34 by pmolnar       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIB_MLX = mlx
LIBFT_NAME = libft.a
LIBFT_PATH = includes/libft/
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

NAME = fractol 
 SRC =	main.c			\
		rendering.c		\
		init.c			\
		colors.c  		\
		fractal.c		\
		event_handler.c \
		events.c		\
		input.c			\
		fractals.c		\
		error.c			\

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB_MLX) $(LIBFT_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT_PATH)$(LIBFT_NAME) -o $(NAME)

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

$(LIBFT_NAME):
	make libft.a -C $(LIBFT_PATH) 

.PHONY: $(LIB_MLX) $(LIBFT_NAME) $(NAME) all clean fclean re