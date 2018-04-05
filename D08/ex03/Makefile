# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 08:56:04 by mbaron            #+#    #+#              #
#    Updated: 2018/04/05 09:58:24 by mbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brainfuck

SRC		= 	main.cpp

OBJ		=	$(SRC:.cpp=.o)

FLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address

GCC		=	clang++-3.5

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(GCC) $(FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
			$(GCC) $(FLAGS) -o $@ -c $<

clean	:
			$(RM) $(OBJ)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all
