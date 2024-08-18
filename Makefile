# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:17:18 by pmendez-          #+#    #+#              #
#    Updated: 2024/07/30 13:17:23 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-g3 -fsanitize=address,leak

FILES = src/pipex.c \
		src/utils.c \
		src/execution.c 

FILES_BONUS = bonus/pipex_bonus.c \
		bonus/treat_memory_bonus.c \
		bonus/utils_bonus.c \
		bonus/execution_bonus.c \
		bonus/duplicate_processes_bonus.c

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@echo "🚀 Compiling..."
	@make -s -C libft
	@$(CC) $(FILES) -L libft -lft -o $(NAME)
	@echo " Compilation finished! 👍"

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "🚀 Compiling..."
	@make -s -C libft
	@$(CC) $(FILES_BONUS) -L libft -lft -o $(NAME_BONUS)
	@echo " Bonus Compilation finished! 👍"

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make fclean -C libft
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -s fclean -C libft
	@rm -f libft/libft.a
	@echo " Deleting finished! 🗑"

upload:
	@if [ -z "$(m)" ]; then \
		echo "Error: Please provide a commit message using 'make upload m=\"Your message\"'"; \
		exit 1; \
	fi
	@git add .
	@git status
	@git commit -m "$(m)"
	@git push

norm: 
	@norminette src/*.c include/*.h libft/*/*.c libft/*.h bonus/*.c

re-bonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re upload norm bonus re-bonus
