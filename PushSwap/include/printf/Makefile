# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbras <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 15:51:23 by tbras             #+#    #+#              #
#    Updated: 2024/02/26 16:49:26 by tbras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCES =	libftprintf.c printf_math.c libftprintf_utils.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

HEADER = libftprintf.h

CFLAGS = -Wall -Werror -Wextra

all:  $(NAME)

$(NAME): $(MY_OBJECTS)
		ar -rcs $(NAME) $(MY_OBJECTS)

clean:
		rm -f $(MY_OBJECTS)

fclean:
		rm -f $(NAME) $(MY_OBJECTS) 

re: fclean all
	
.PHONY: fclean clean all re
















