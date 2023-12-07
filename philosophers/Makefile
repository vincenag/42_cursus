# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 10:50:45 by agvincen          #+#    #+#              #
#    Updated: 2023/12/07 13:35:02 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = src/main.c\
		src/utils.c\

OBJECTS = $(FILES:.c=.o)

CC 		= gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m


all: $(NAME)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

$(OBJECTS): %.o: %.c
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< || (echo "Compilation failed for $<" && false)


$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re