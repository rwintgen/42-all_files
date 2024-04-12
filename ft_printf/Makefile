# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:53:09 by rwintgen          #+#    #+#              #
#    Updated: 2023/11/13 12:53:10 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_format.c\
			ft_printf.c\
			ft_printfchar.c\
			ft_printfnbr.c\
			ft_printfnbrhex.c\
			ft_printfnbru.c\
			ft_printfptr.c\
			ft_printfstr.c\
			ft_strlen.c

OBJS	=	$(SRCS:.c=.o)

LD		=	ar

LDFLAGS	=	rcs

RM		=	rm -f

$(NAME):	$(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	${NAME}


clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
