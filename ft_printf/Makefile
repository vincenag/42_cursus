# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 14:49:47 by agvincen          #+#    #+#              #
#    Updated: 2023/05/31 12:57:25 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
DIRLIBFT = ./libft

FILES = \
	ft_printf.c\
	ft_print_c.c\
	ft_print_s.c\
	ft_print_p.c\
	ft_print_d.c\
	ft_print_x.c\
	ft_print_i.c\
	ft_print_u.c\

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

makelibft:
	make -C $(DIRLIBFT)
	cp $(DIRLIBFT)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJECTS)
	ar rs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	gcc $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJECTS)
	cd $(DIRLIBFT) && make clean

fclean: clean
		rm -f $(NAME)
		cd $(DIRLIBFT) && make fclean

re: fclean all

.PHONY: all makelibft clean fclean re
