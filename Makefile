# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 15:23:21 by nihamila          #+#    #+#              #
#    Updated: 2023/07/10 15:16:00 by nihamila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= src
OBJ_DIR			= obj
INC_DIR			= include
LIB_DIR			= lib

CC				= clang

RM				= rm -f

NAME			= so_long

CFLAGS			= -Wall -Wextra -Werror

LIBS			= ./lib/libft/libft.a

SRCS			= $(addprefix $(SRC_DIR)/, parsing.c main.c)

OBJS			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

OBJS =			$(SRCS:.c=.o)

DEPS			= $(addprefix $(INC_DIR)/, so_long.h)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(DEPS)
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIB_DIR)/libft
				$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $@

clean:
				make clean -C $(LIB_DIR)/libft
				$(RM) $(OBJS)

fclean:
				make fclean -C $(LIB_DIR)/libft
				$(RM) $(OBJS)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re