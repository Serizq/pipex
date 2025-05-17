# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:29:49 by seizquie          #+#    #+#              #
#    Updated: 2025/04/11 18:06:09 by seizquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
      ft_memcpy.c ft_memmove.c \
      ft_memcmp.c ft_memset.c ft_putchar_fd.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
      ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlcpy.c \
      ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strnstr.c \
      ft_strmapi.c ft_strtrim.c \
      ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_substr.c \
      ft_atol.c ft_bubblesort.c ft_error.c ft_error_clean.c ft_index.c ft_sqrt.c\
      ft_free_array.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
