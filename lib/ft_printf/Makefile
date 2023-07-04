# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 14:39:59 by nihamila          #+#    #+#              #
#    Updated: 2023/04/14 17:03:36 by nihamila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c ft_printhexa.c ft_putchar.c ft_putnbr_unsigned.c\
		ft_putnbr.c ft_putptr.c ft_strchr.c ft_putstr.c ft_strlen.c\

OBJS = ${SRCS:.c=.o}

RM = rm -f

all : ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean bonus re
