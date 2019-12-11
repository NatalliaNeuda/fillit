# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:01:46 by nneuda            #+#    #+#              #
#    Updated: 2019/12/11 14:41:26 by nneuda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = *.c 
OBJS = *.o
HEADER = fillit.h 
FLAGS = -Wall -Wextra -Werror 
SANIT = -fsanitize=address

LIBFT = LIBFT/

all: $(NAME)
	
$(NAME): $(SRCS) $(HEADER)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. LIBFT/libft.a

sanit:
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. LIBFT/libft.a $(SANIT) -g

debug:
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. LIBFT/libft.a -g
	lldb $(NAME) -- sample.txt

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
