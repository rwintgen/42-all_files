# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:38:48 by romain            #+#    #+#              #
#    Updated: 2024/09/07 10:53:59 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		PmergeMe

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					PmergeMe.cpp

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