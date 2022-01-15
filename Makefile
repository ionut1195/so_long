NAME = so_long
SRCS = ./sources/so_long.c ./sources/map.c ./sources/exit.c ./sources/handlers.c ./sources/inits.c ./sources/validate.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = mlx/libmlx_Darwin.a -L/usr/X11/lib -I/opt/X11/include -lXext -lX11 -lm -lz -g -o
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME): config $(OBJS)
	$(MAKE)	-C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) $(CFLAGS) -o $(NAME) -Llibft -lft
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)
	cd mlx && make clean
fclean:
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)
	cd mlx && make clean
config:
	cd mlx && bash ./configure
re: fclean all
.PHONY: all clean fclean re