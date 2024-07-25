# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 15:16:33 by romain            #+#    #+#              #
#    Updated: 2024/07/25 15:20:41 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fstrrep

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp

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