# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 16:24:32 by itomescu          #+#    #+#              #
#    Updated: 2022/01/03 20:01:07 by itomescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
NAME = libft.a
HEAD = libft.h
SRCS = \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memset.c \
	ft_memcmp.c ft_calloc.c ft_memchr.c ft_strdup.c \
	ft_strrchr.c ft_strnstr.c ft_itoa.c ft_atoi.c \
	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_strjoin.c ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c \
	ft_strmapi.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c  ft_gnl.c ft_has_newline.c ft_get_newline_index.c
OBJS = $(SRCS:.c=.o)
BONUS = \
	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
	ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o \
	ft_lstiter.o

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c $(HEAD)
	$(CC) -c $(CFLAGS)  -o $@  $<

clean:
	echo "Remove .o  ..."
	rm -f $(OBJS) $(BONUS)

fclean: clean
	echo "Remove lib ..."
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS)

bonus: $(OBJS) $(BONUS)
	ar rc $(NAME) $(OBJS) $(BONUS)

.PHONY: all clean fclean re bonus so