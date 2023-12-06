# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 15:23:21 by nihamila          #+#    #+#              #
#    Updated: 2023/12/06 22:00:46 by nisarhamila      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

############################ * F I L E S * #####################################

SRCS = 	src/main.c \
		src/parsing.c\
		src/parsing_utils.c\
		src/fload_fill.c\
		src/mlx.c\
		src/mlx_utils.c\
		src/move.c\
		src/move_utils.c\

OBJS = $(SRCS:.c=.o)

######################### * C O M P I L A T I O N * ##############################
CC 				= gcc
CFLAGS 			= -Werror -Wall -Wextra
RM 				= rm -rf
MAKE_EXT 		= @make -s --no-print-directory -C
OBJ				= ${OBJS}
UNAME_S			= $(shell uname -s)

LIBS 			= -L ./libft -lft -framework OpenGL -framework AppKit 

COMPIL			= $(CC) $(CFLAGS) ${OBJ} libmlx.a $(LIBS) -o $(NAME)

################################# * R U L E S * #####################################
$(NAME):	${OBJ}
			@printf $(blue)
			@printf "\n"
			@printf $(magenta)
			$(MAKE_EXT) ./libft bonus
			@$(COMPIL)
			@printf $(reset)

all : $(NAME)

%.o: %.c
			@printf $(red)
			@printf "\r\033[K⏳ Compilation de ""$(YEL)${notdir $<}$(EOC). ⏳"
			@$(CC) -c $(CFLAGS) -Imlx -o $@ $<
			@printf $(reset)

clean:
			$(MAKE_EXT) ./libft bonus clean
			@${RM} ${OBJ} 
			@printf $(yellow)
			@echo "🗑  $(GRE)Supression des fichiers binaires (.o).$(EOC) 🗑"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft bonus fclean
			@${RM} $(NAME)
			@printf $(green)
			@echo "🗑  $(YEL)Supression des executables et librairies.$(EOC) 🗑"
			@printf $(reset)

re : fclean all

.PHONY: 	all clean fclean re 

black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"

reset 				=	"[0m"

RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[34m
YEL		=	\033[33m
EOC		=	\033[0m