# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:01:46 by nneuda            #+#    #+#              #
#    Updated: 2019/12/11 23:19:23 by hyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = read.c map.c validation.c solver.c f_def.c
OBJS = read.o map.o validation.o solver.o f_def.o
HEADER = fillit.h 
FLAGS = -Wall -Wextra -Werror 

LIBFT = libft/

all: $(NAME)
	
$(NAME): $(SRCS) $(HEADER)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. libft/libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
