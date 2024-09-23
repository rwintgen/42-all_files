# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:28:22 by romain            #+#    #+#              #
#    Updated: 2024/09/23 11:38:01 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		FragTrap

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp

OBJ			=		$(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re