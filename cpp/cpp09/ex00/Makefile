# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 16:58:45 by romain            #+#    #+#              #
#    Updated: 2024/11/05 13:28:12 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		btc

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					BitcoinExchange.cpp

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