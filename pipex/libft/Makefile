# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:30:27 by rwintgen          #+#    #+#              #
#    Updated: 2024/03/18 18:12:14 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c \
		ft_atol.c \
		ft_atoll.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_printf/ft_format.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printfchar.c \
		ft_printf/ft_printfnbr.c \
		ft_printf/ft_printfnbrhex.c \
		ft_printf/ft_printfnbru.c \
		ft_printf/ft_printfptr.c \
		ft_printf/ft_printfstr.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_free_char_tab.c

OBJS    = ${SRCS:.c=.o}

NAME    = libft.a

CC  = gcc

AR    = ar rcs

CFLAGS  = -Wall -Wextra -Werror -g

RM  = rm -f

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:		${NAME}

bonus:		$(OBJS)
		$(AR) $(NAME) $?

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
