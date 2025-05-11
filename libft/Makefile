# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:29:39 by gule-bat          #+#    #+#              #
#    Updated: 2025/04/13 13:36:29 by gule-bat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs
INCLUDES_DIR = includes

SRCS =	ft_atoi.c     ft_isdigit.c  ft_memmove.c  ft_strlcat.c  ft_strrchr.c \
		ft_bzero.c    ft_isprint.c  ft_memset.c   ft_strlcpy.c  ft_strtrim.c \
		ft_calloc.c   ft_itoa.c     ft_split.c    ft_strlen.c   ft_substr.c \
		ft_isalnum.c  ft_memchr.c   ft_strchr.c	  ft_strmapi.c	ft_tolower.c \
		ft_isalpha.c  ft_memcmp.c   ft_strdup.c   ft_strncmp.c  ft_toupper.c \
		ft_isascii.c  ft_memcpy.c   ft_strjoin.c  ft_strnstr.c	ft_striteri.c \
		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o) 

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES_DIR) -g3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
