# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 15:40:45 by romain            #+#    #+#              #
#    Updated: 2024/09/26 13:44:15 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		WorldOnFire

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					Animal.cpp \
					Brain.cpp \
					Dog.cpp \
					Cat.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp

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