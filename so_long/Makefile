# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 22:21:34 by agvincen          #+#    #+#              #
#    Updated: 2023/09/08 16:15:33 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
NAME_BONUS = so_long_bonus

LIBFTHEADER = ./libft/libft.h
LIBFTLIB = ./libft/libft.a
MLXHEADER = ./mlx/include/MLX42/MLX42.h
MLXLIB = ./mlx/libmlx42.a


HEADERS	:= -I $(MLXHEADER) -I $(LIBFTHEADER)
LIBS	:= $(LIBFTLIB) $(MLXLIB) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
FILES = src/so_long.c src/map.c\
			src/graphics.c\
			src/utils.c\
			src/check.c\
			src/valid_path.c\
			src/controls.c\
			src/conditions.c\

FILES_BONUS = src_bonus/check_bonus.c\
				src_bonus/conditions_bonus.c\
				src_bonus/controls_bonus.c\
				src_bonus/enemy_bonus.c\
				src_bonus/graphics_bonus.c\
				src_bonus/map_bonus.c\
				src_bonus/so_long_bonus.c\
				src_bonus/utils_bonus.c\
				src_bonus/valid_path_bonus.c\
				
OBJECTS = $(FILES:.c=.o)
OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

CC 		= gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: libmlx liblibft $(NAME)
	@echo "\n$(ORANGE)$(U_LINE) $(NAME): Compiled $(RESET) \n"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"


libmlx:
	@$(MAKE) -C ./mlx

liblibft:
	@$(MAKE) -C ./libft
	@echo "\n$(ORANGE)$(U_LINE)⭐️ Libft: Compiled ⭐️$(RESET) \n"

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

bonus: libmlx liblibft $(NAME_BONUS)
	@echo "\n$(ORANGE)$(U_LINE) $(NAME_BONUS): Compiled $(RESET) \n"

$(NAME_BONUS): $(OBJECTS_BONUS)
	@$(CC) $(OBJECTS_BONUS) $(LIBS) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C ./libft 
	@$(MAKE) clean -C ./mlx
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft 
	@$(MAKE) fclean -C ./mlx
	@rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re bonus