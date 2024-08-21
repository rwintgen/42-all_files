# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 19:57:10 by romain            #+#    #+#              #
#    Updated: 2024/08/21 12:00:49 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		Forms

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98

SRC			=		main.cpp \
					Bureaucrat.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp

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