# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 15:23:21 by nihamila          #+#    #+#              #
#    Updated: 2023/07/04 18:17:49 by nihamila         ###   ########.fr        #
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

LIBS			= -L$(LIB_DIR) -lft -lftprintf -lftget_next_line

SRCS			= $(addprefix $(SRC_DIR)/, ) 

OBJS			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

DEPS			= $(addprefix $(INC_DIR)/, so_long.h)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(DEPS)
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIB_DIR)/libft
				make -C $(LIB_DIR)/ft_printf
				make -C $(LIB_DIR)/get_next_line
				$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $@

clean:
				make clean -C $(LIB_DIR)/libft
				make clean -C $(LIB_DIR)/ft_printf
				make -C $(LIB_DIR)/get_next_line
				$(RM) $(OBJS)

fclean:
				make fclean -C $(LIB_DIR)/libft
				make fclean -C $(LIB_DIR)/ft_printf
				make -C $(LIB_DIR)/get_next_line
				$(RM) $(OBJS)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re