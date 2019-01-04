# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 00:44:52 by jaelee            #+#    #+#              #
#    Updated: 2019/01/04 09:54:54 by jaelee           ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./ -I./libft

.PHONY: clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) libft/libft.a
	gcc -Llibft -lft $^ -o $@

%.o : %.c
	gcc $(CFLAGS) $(INCLUDES) -c $^ -o $@

libft/libft.a :
	make -C libft

clean :
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft libclean
	rm -f $(NAME)

re : fclean
	make all
