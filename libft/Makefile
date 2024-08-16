# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 18:05:22 by pmendez-          #+#    #+#              #
#    Updated: 2023/09/21 18:05:25 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

FILES = ./ft_printf/ft_printf.c \
		./ft_printf/ft_printstr.c \
		./ft_printf/ft_print_integer.c \
		./ft_printf/ft_printchar.c \
		./ft_printf/ft_printpointer.c \
		./ft_printf/ft_print_hexa.c \
		./ft_printf/ft_print_unsigned_int.c \
		./ft_printf/ft_printstr.c \
		./char_management/ft_split.c \
		./char_management/ft_strchr.c \
		./char_management/ft_strrchr.c \
		./char_management/ft_striteri.c \
		./char_management/ft_strjoin.c \
		./char_management/ft_strlcpy.c \
		./char_management/ft_strlcat.c \
		./char_management/ft_strmapi.c \
		./char_management/ft_strncmp.c \
		./char_management/ft_strnstr.c \
		./char_management/ft_strtrim.c \
		./char_management/ft_substr.c \
		./file_functions/ft_putchar_fd.c \
		./file_functions/ft_putendl_fd.c \
		./file_functions/ft_putnbr_fd.c \
		./file_functions/ft_putstr_fd.c \
		./get_next_line/get_next_line_bonus.c \
		./linked_list/ft_lstadd_back_bonus.c \
		./linked_list/ft_lstadd_front_bonus.c \
		./linked_list/ft_lstclear_bonus.c \
		./linked_list/ft_lstdelone_bonus.c \
		./linked_list/ft_lstiter_bonus.c \
		./linked_list/ft_lstlast_bonus.c \
		./linked_list/ft_lstmap_bonus.c \
		./linked_list/ft_lstnew_bonus.c \
		./linked_list/ft_lstsize_bonus.c \
		./memory_functions/ft_memchr.c \
		./memory_functions/ft_memcmp.c \
		./memory_functions/ft_memcpy.c \
		./memory_functions/ft_memmove.c \
		./memory_functions/ft_memset.c \
		./numbers/ft_atoi.c \
		./numbers/ft_itoa.c \
		./others/ft_bzero.c \
		./others/ft_calloc.c \
		./others/ft_strdup.c \
		./simple_functions/ft_isalnum.c \
		./simple_functions/ft_isalpha.c \
		./simple_functions/ft_isascii.c \
		./simple_functions/digit.c \
		./simple_functions/ft_isprint.c \
		./simple_functions/ft_strlen.c \
		./simple_functions/ft_tolower.c \
		./simple_functions/ft_toupper.c \

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

ejecutar:
	$(CC) $(CFLAGS) $(NAME)
	./a.out

clean:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
