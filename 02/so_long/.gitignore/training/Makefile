NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra 
MLX = libmlx.a
SRC = square.c
OBJ = $(SRC:.c=.o)

all: $(MLX) $(NAME)

$(MLX): 
	make -C ../mlx/

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -D -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
