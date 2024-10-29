# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:18:25 by rwintgen          #+#    #+#              #
#    Updated: 2024/10/29 16:31:21 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		Materia

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					MateriaSource.cpp

OBJ			=		$(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re