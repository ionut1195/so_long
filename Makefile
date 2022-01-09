NAME = so_long
SRCS = so_long.c map.c
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = mlx/libmlx.a -L/usr/X11/lib -I/opt/X11/include -lXext -lX11 -lm -lz -g -o
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE)	-C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) $(CFLAGS) -o $(NAME) -Llibft -lft
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)
fclean:
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re