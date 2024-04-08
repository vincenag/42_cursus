# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 17:22:16 by agustin           #+#    #+#              #
#    Updated: 2024/04/04 15:25:50 by agvincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FILES = Megaphone.cpp

OBJECTS = $(FILES:.cpp=.o)

CCX = c++
CXXFLAGS	:= -std=c++98 -Wextra -Wall -Werror -Wunreachable-code -Ofast
ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)
	@echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $< && printf "Compiling: $<\n"

$(NAME): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re