# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 00:26:46 by vcastilh          #+#    #+#              #
#    Updated: 2022/09/17 07:25:16 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 
LIBFT = libft.a
SRCS = main.c \
	   rules.c \
	   sort.c \
	   parsing.c \
	   utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft/$(LIBFT)
	$(CC) $(OBJS) -Llibft -lft -o $(NAME) 

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) -Ilibft $(SRCS) 

libft/$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
