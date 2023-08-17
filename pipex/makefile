# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 19:56:53 by agvincen          #+#    #+#              #
#    Updated: 2023/08/10 14:34:02 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

DIRLIBFT = ./libft

FILES = pipex.c	utils.c
OBJECTS = $(FILES:.c=.o)

FILES_BONUS = pipex_bonus.c utils_bonus.c
OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o: %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make re -C $(DIRLIBFT)
	@$(CC) $(OBJECTS) -L$(DIRLIBFT) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	@make re -C $(DIRLIBFT)
	@$(CC) $(OBJECTS_BONUS) -L$(DIRLIBFT) -lft -o $(NAME_BONUS)

clean:
	@make clean -C $(DIRLIBFT)
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@make fclean -C $(DIRLIBFT)
	@rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus