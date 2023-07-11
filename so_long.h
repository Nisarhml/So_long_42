/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:24:26 by nihamila          #+#    #+#             */
/*   Updated: 2023/07/11 17:06:47 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line_bonus.h"

typedef struct s_map {
	
	char	**full_map;
	int		line;
	int		count_char;

}	t_map;

int		check_if_ber(int argc, char **argv);
void	count_line(t_map *map, char *str);
void	init_map(t_map *map, char *str);
void	check_valid_char(t_map *map);
void	check_if_square(t_map *map);
void	check_if_closed(t_map *map);
void	count_valid_char(t_map *map, int c, int e, int p);
# endif