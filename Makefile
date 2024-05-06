# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:54:14 by siyu              #+#    #+#              #
#    Updated: 2024/05/02 18:20:15 by siyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC =  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c \
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c ft_calloc.c ft_atoi.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	echo "$(NAME) Created"

bonus: .bonus

.bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
	echo "$(NAME) with bonus Created"
	touch .bonus

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ) .bonus
	@echo "OBJ and bonus marker deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, bonus, clean, fclean, re


