# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 08:56:04 by mbaron            #+#    #+#              #
#    Updated: 2018/03/16 14:18:56 by mbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	eval_expr

SRC		= 	main.cpp \
			Fixed.cpp

OBJ		=	$(SRC:.cpp=.o)

FLAGS	=	-Wall -Werror -Wextra

GCC		=	clang++

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
