


SRC = src/*.c
SRC_L = library/libft/*.c

all:
	make -C library/minilibx-linux
	cc -Wall -Wextra -Werror $(SRC_L) $(SRC) -Llibrary/minilibx-linux -lmlx -lX11 -lm -lXext -Ilibrary/minilibx-linux -o so_long