/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:08:11 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/12/06 22:02:45 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_map *map)
{
	map->line = 0;
	map->count_char = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->moves = 0;
	map->mlx_ptr = 0;
	map->win_ptr = 0;
	map->player = 0;
	map->floor = 0;
	map->wall = 0;
	map->items = 0;
	map->exit = 0;
}

int	count_collect(t_map *map)
{
	int	collect;
	int	y;
	int	x;

	collect = 0;
	y = 0;
	while (map->full_map[y] != NULL)
	{
		x = 0;
		while (map->full_map[y][x] != '\0')
		{
			if (map->full_map[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
	return (collect);
}
