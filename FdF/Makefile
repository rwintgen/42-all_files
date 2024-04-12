# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:31:22 by rwintgen          #+#    #+#              #
#    Updated: 2024/01/31 16:48:35 by rwintgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -O0 -g
LIBMLX	:= ./MLX42
LIBFT	:= ./libft/
LIBFTA	:= $(LIBFT)/libft.a

HEADERS	:= -I ./includes -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBFTA) $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 
SRCS	:= sources/draw_map.c \
			sources/fdf.c \
			sources/parse_map.c \
			sources/utils.c \
			sources/utils2.c 

BSRCS	:= sources_bonus/draw_map_bonus.c \
			sources_bonus/fdf_bonus.c \
			sources_bonus/mod_utils_bonus.c \
			sources_bonus/mod_bonus.c \
			sources_bonus/parse_map_bonus.c \
			sources_bonus/utils_bonus.c \
			sources_bonus/utils2_bonus.c 

OBJS	:= $(SRCS:.c=.o)
BOBJS	:= $(BSRCS:.c=.o)

all: libft libmlx $(NAME)

bonus: libft libmlx $(NAME)_bonus

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

./libft/libft.a:
	make -sC $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): ./libft/libft.a $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME)_bonus: ./libft/libft.a $(BOBJS)
	@$(CC) $(BOBJS) $(LIBS) $(HEADERS) -o $(NAME)_bonus

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BOBJS)
	@rm -rf $(LIBMLX)/build
	@cd $(LIBFT) && make clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME)_bonus
	@rm -r $(LIBFTA)

re: fclean all
