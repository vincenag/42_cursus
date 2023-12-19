# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 10:50:45 by agvincen          #+#    #+#              #
#    Updated: 2023/12/19 10:22:13 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src
OBJ_DIR = obj
CC 		= gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

FILES = $(SRC_DIR)/main.c\
		$(SRC_DIR)/check_args.c\
		$(SRC_DIR)/init.c\
		$(SRC_DIR)/philos.c\
		$(SRC_DIR)/philo_check.c\
		$(SRC_DIR)/utils.c\
		$(SRC_DIR)/exit.c\

OBJECTS = $(FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


ORANGE = \033[1;38;5;208m
GREEN	= \033[32;1m
CIAN	= \033[36m
BLUE	= \033[1;38;5;27m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m
END 	= \033[0m


all: $(OBJ_DIR) $(NAME)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)Philo Compiling:$(END) $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(CFLAGS) -fsanitize=thread -g3 -o $@ 
	@echo "\n$(GREEN)[Compiled $(CIAN) $@ $(GREEN)successfully]\n"

#-fsanitize=thread -g3

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)[Removed $(CIAN) $(NAME) $(GREEN)successfully]\n$(END)"

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re