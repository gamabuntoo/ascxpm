NAME = ascxpm

SRCS = main.c

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -O3

make:
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	rm $(NAME)

