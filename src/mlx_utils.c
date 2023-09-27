/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:51:37 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/09/27 19:42:35 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == 0)
		ft_printf("Error, init library failed\n");
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->count_char * 64),
			(map->line * 64), "So_long");
	if (map->win_ptr == 0)
		ft_printf("Error, init window failed\n");
}

void	player_position(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->full_map[++y])
	{
		x = -1;
		while (map->full_map[y][++x])
		{
			if (map->full_map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
		}
	}
}

int	collect_items(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	map->collect = 0;
	while (map->full_map[++y])
	{
		x = -1;
		while (map->full_map[y][++x])
		{
			if (map->full_map[y][x] == 'C')
				map->collect++;
		}
	}
	return (map->collect);
}

int	game_over(t_map *map)
{
	free(map->full_map);
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_image(map->mlx_ptr, map->floor);
	mlx_destroy_image(map->mlx_ptr, map->player);
	mlx_destroy_image(map->mlx_ptr, map->items);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_image(map->mlx_ptr, map->win_ptr);
	free(map->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	print_moves(t_map *map)
{
	char	*move;
	char	*text;

	move = ft_itoa(map->moves);
	text = ft_strjoin("Movements : ", move);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 30, 0xFF0000, text);
	free(move);
	free(text);
}
