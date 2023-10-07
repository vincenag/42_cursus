# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 12:56:48 by agvincen          #+#    #+#              #
#    Updated: 2023/09/28 01:07:40 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTHEADER = ./libft
LIBFTLIB = ./libft/libft.a

HEADERS	:= -I $(LIBFTHEADER)
LIBS	:= $(LIBFTLIB)
FILES = src/main.c\
			src/push.c\
			src/swap.c\
			src/rotate.c\
			src/rev_rotate.c\
			src/utils.c\
			src/set_up.c\
			src/algorit.c\
			src/many_utils.c\
			src/many_utils_2.c\
			src/many_utils_3.c\

OBJECTS = $(FILES:.c=.o)

CC 		= gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m


all: liblibft $(NAME)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

liblibft:
	@$(MAKE) -C ./libft
	@echo "\n$(ORANGE)$(U_LINE)⭐️ Libft: Compiled ⭐️$(RESET) \n"

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft 
	@rm -rf $(OBJECTS)

fclean: clean
	@$(MAKE) fclean -C ./libft 
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re