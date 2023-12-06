/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:51:49 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/12/06 17:17:03 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->player, y * 64, x * 64);
}

void	put_items(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->items, y * 64, x * 64);
}

void	put_wall(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->wall, y * 64, x * 64);
}

void	put_images_in_game(t_map *map)
{
	int	i;
	int	j;

	map->floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/floor.xpm", &i, &j);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/wall.xpm", &i, &j);
	map->player = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/Luffy_standing.xpm", &i, &j);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/Exit_boat.xpm", &i, &j);
	map->items = mlx_xpm_file_to_image(map->mlx_ptr,
			"./src/image/Bone_meat.xpm", &i, &j);
	if (!map->floor || !map->wall || !map->player || !map->exit || !map->items)
	{
		free(map->win_ptr);
		free(map->mlx_ptr);
		ft_printf("Error, image files are missing\n");
		exit(EXIT_FAILURE);
	}
}

int	adding_in_graphics(t_map *map)
{
	int	i;
	int	j;

	put_images_in_game(map);
	i = -1;
	while (map->full_map[++i])
	{
		j = -1;
		while (map->full_map[i][++j])
		{
			mlx_put_image_to_window(map->mlx_ptr,
				map->win_ptr, map->floor, j * 64, i * 64);
			if (map->full_map[i][j] == '1')
				put_wall(map, j, i);
			else if (map->full_map[i][j] == 'C')
				put_items(map, j, i);
			else if (map->full_map[i][j] == 'P')
				put_player(map, j, i);
			else if (map->full_map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx_ptr,
					map->win_ptr, map->exit, j * 64, i * 64);
			print_moves(map);
		}
	}
	return (0);
}
