# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 11:04:33 by agvincen          #+#    #+#              #
#    Updated: 2024/06/11 16:34:54 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = RPN

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = main.cpp\
		RPN.cpp
		
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

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all show clean fclean re