/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:24:26 by nihamila          #+#    #+#             */
/*   Updated: 2023/09/06 14:51:03 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct s_map {
	
	char	**full_map;
	char	**cpy_full_map;
	int		line;
	int		count_char;
	int		collect;
	int		player_x;
	int		player_y;
	int		moves;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*floor;
	void	*wall;
	void	*items;
	void	*exit;

}	t_map;

/*===============================PARSING======================================*/

int		check_if_ber(int argc, char **argv);
void	count_line(t_map *map, char *str);
void	init_map(t_map *map, char *str);
void	check_valid_char(t_map *map);
void	check_if_square(t_map *map);
void	check_if_closed(t_map *map);
void	count_valid_char(t_map *map, int c, int e, int p);
void	copy_map(t_map *map, char *str);
void	fload_fill(t_map *map, int x, int y);
void	check_valid_path(t_map *map);
void	check_after_fill(t_map *map);

# endif