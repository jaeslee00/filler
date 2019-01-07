# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 00:44:52 by jaelee            #+#    #+#              #
#    Updated: 2019/01/07 03:58:27 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jaelee.filler
SRCS = main.c \
	   parser.c \
	   init_nmap.c \
	   process_nmap.c \
	   filler.c \
	   ft_atoi_ptr.c \
	   free_and_error.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./ -I./libft

.PHONY: clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) -Llibft -lft $^ -o $@

%.o: %.c filler.h libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft libclean
	rm -f $(NAME)

re: fclean
	make all
