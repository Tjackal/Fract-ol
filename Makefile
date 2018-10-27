NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx/

_SRC = fractol.c sets.c sets2.c scale_move_mllc_quit.c params.c zhp.c key_mouse_re.c

SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) fractol.h
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft -g -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: $(SRC_DIR)%.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all