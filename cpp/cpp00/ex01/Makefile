# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 12:39:28 by rwintgen          #+#    #+#              #
#    Updated: 2024/09/18 13:35:31 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp

OBJ			=	$(SRC:.cpp=.o)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re