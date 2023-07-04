# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 13:06:01 by nihamila          #+#    #+#              #
#    Updated: 2023/04/11 15:23:49 by nihamila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalnum.c ft_isprint.c ft_isalpha.c ft_bzero.c ft_memcpy.c\
		ft_isascii.c ft_isdigit.c ft_memset.c ft_strlen.c ft_memmove.c\
		ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strlcat.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strtrim.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c\

SRCS_BONUS = 	ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c\
				ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c\
				ft_lstiter.c ft_lstmap.c\


OBJS = ${SRCS:.c=.o}

OBJS_BONUS =  ${SRCS_BONUS:.c=.o}

RM = rm -f

all : ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_BONUS}
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
	
clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean bonus re
