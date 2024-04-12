# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 11:13:31 by aranger           #+#    #+#              #
#    Updated: 2023/10/07 11:28:14 by aranger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
NAME = rush-02
CFLAG += -Wall -Wextra -Werror
MY_SOURCES = ft_function.c \
      ft_functions_for_print_num.c \
      ft_islegit.c \
      ft_print_num.c \
      ft_read_file.c \
      ft_sort_in_tab.o main.c
MY_OBJECTS =  ft_function.o \
	ft_functions_for_print_num.o \
	ft_islegit.o \
	ft_print_num.o \
	ft_read_file.o \
	ft_sort_in_tab.o \
	main.o

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAG)

$(NAME) : $(MY_OBJECTS)
	$(CC) -o $@ $(MY_OBJECTS)

clean :
	rm -rf *.o

fclean : clean
	rm -rf rush-02
