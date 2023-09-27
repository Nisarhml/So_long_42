/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fload_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:51:24 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/09/27 19:07:01 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_map *map, char *str)
{
	int	i;
	int	j;

	i = open(str, O_RDONLY);
	map->cpy_full_map = malloc((sizeof(char *) + 1) * map->line);
	j = 0;
	map->cpy_full_map[j] = get_next_line(i);
	while (j < map->line)
	{
		j++;
		map->cpy_full_map[j] = get_next_line(i);
	}
	map->cpy_full_map[j] = 0;
	close(i);
}

void	fload_fill(t_map *map, int x, int y)
{
	if (map->cpy_full_map[x][y] != '1' && map->cpy_full_map[x][y] != 'F')
	{
		map->cpy_full_map[x][y] = 'F';
		fload_fill(map, x - 1, y);
		fload_fill(map, x + 1, y);
		fload_fill(map, x, y - 1);
		fload_fill(map, x, y + 1);
	}
}

void	check_valid_path(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->cpy_full_map[++i])
	{
		j = -1;
		while (map->cpy_full_map[i][++j])
		{
			if (map->cpy_full_map[i][j] == 'P')
			{
				fload_fill(map, i, j);
				j = 0;
			}
		}
	}
}

void	check_after_fill(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->cpy_full_map[++i])
	{
		j = 0;
		while (map->cpy_full_map[i][++j])
		{
			if (map->cpy_full_map[i][j] == 'C')
			{
				ft_printf("invalid path !\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
