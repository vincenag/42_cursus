# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agustin <agustin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 22:03:08 by agustin           #+#    #+#              #
#    Updated: 2024/04/02 18:39:16 by agustin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = main.cpp\
		Fixed.cpp\
		
OBJS = $(SRCS:.cpp=.o)

GREEN   =   \033[92;5;118m
YELLOW  =   \033[93;5;226m
CIAN    = \033[36m
BLUE    = \033[1;38;5;27m
END     = \033[0m

all: $(NAME)

show:
    @printf "NAME   : $(NAME)\n"
    @printf "CC  : $(CC)\n"
    @printf "FLAGS   : $(FLAGS)\n"
    @printf "SRCS    :$(addprefix \n\t , $(notdir $(SRCS)))\n"

clean:
	@$(RM) *.o
	@echo "$(YELLOW)- Object files removed.$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)- Executable removed.$(END)"

re: fclean all

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)\n[Compiled$(CIAN) $@ $(GREEN)successfully]$(END)"

.PHONY: all show clean fclean re