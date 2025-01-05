# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 19:01:34 by nmartin           #+#    #+#              #
#    Updated: 2025/01/02 15:34:17 by nmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wextra -Werror -Wall
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \
					ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c \
						ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
							ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c								
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
SRC_PRINTF = ft_printf.c ft_printf_conv.c ft_printf_conv1.c ft_printf_conv2.c \
		ft_printf_utils.c ft_errors.c ft_check_bonus.c ft_bonus_utils.c \
			ft_b_checks.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
