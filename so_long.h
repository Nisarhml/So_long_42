/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:24:26 by nihamila          #+#    #+#             */
/*   Updated: 2023/07/10 14:57:21 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line_bonus.h"

typedef struct s_map {
	
	char	**cpy_map;

}	t_map;

int	check_if_ber(int argc, char **argv);

# endif