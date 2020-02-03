# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 01:59:14 by mvo-van-          #+#    #+#              #
#    Updated: 2019/01/04 01:59:19 by mvo-van-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
CFLAGS  =   -Wall -Wextra -Werror -I $(LIB)
CC      =   gcc
LIB		=   ./libft/
SRC		=	main.c 			\
			checks.c		\
			backtrack.c		\
			utiles.c		\
			freefun.c

INC_NAME = fillit.h
	
OFILES = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OFILES)
		make -C $(LIB) 
		$(CC) -o $(NAME) $(OFILES) -L $(LIB) -lft
clean:
		make -C $(LIB) clean
	    rm -f $(OFILES)
fclean: clean
		make -C $(LIB) fclean
	    rm -f $(NAME)
re: fclean all

.PHONY : all, $(NAME), clean, fclean, re
