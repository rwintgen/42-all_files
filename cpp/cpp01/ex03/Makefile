# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 13:11:51 by romain            #+#    #+#              #
#    Updated: 2024/07/25 13:38:48 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		violence

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					HumanA.cpp \
					HumanB.cpp \
					Weapon.cpp

OBJ			=		$(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@rm $(OBJ)

fclean:
	@rm  $(OBJ) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re