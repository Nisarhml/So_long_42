/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:00:29 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/09/27 20:04:24 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_move(t_map *map, int i, int j)
{
	if (map->full_map[j][i] == 'E' && map->collect == 0)
	{
		ft_printf("\n Congrats, You found the ONE PIECE\n");
		game_over(map);
	}
	if (map->full_map[j][i] == '0')
	{
		map->full_map[j][i] = 'P';
		map->player_x = i;
		map->player_y = j;
		map->moves++;
	}
	if (map->full_map[j][i] == 'C')
	{
		map->full_map[j][i] = 'P';
		map->player_x = i;
		map->player_y = j;
		map->collect--;
		map->moves++;
	}
	return (0);
}

static int	keyboard_right_and_left(t_map *map, int move)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (move == 13 || move == 126)
	{
		j--;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		map->full_map[j + 1][i] = '0';
	}
	else if (move == 1 || move == 125)
	{
		j++;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		map->full_map[j - 1][i] = '0';
	}
	ft_printf("Movement : %i\n", map->moves);
	return (1);
}

static int	keyboard_up_and_down(t_map *map, int move)
{
	int	i;
	int	j;

	i = map->player_x;
	j = map->player_y;
	if (move == 0 || move == 123)
	{
		i--;
		if (map->full_map[i][j] == '1')
			return (0);
		init_move(map, i, j);
		map->full_map[j][i + 1] = '0';
	}
	else if (move == 2 || move == 124)
	{
		i++;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		map->full_map[j][i - 1] = '0';
	}
	ft_printf("Movement : %i\n", map->moves);
	return (1);
}

int	key_pressed(int key, t_map *map)
{
	int	k;

	k = 0;
	if (key == 53)
		exit (0);
	if (key == 13 || key == 126)
		k = keyboard_right_and_left(map, key);
	if (key == 1 || key == 125)
		k = keyboard_right_and_left(map, key);
	if (key == 0 || key == 123)
		k = keyboard_up_and_down(map, key);
	if (key == 2 || key == 124)
		k = keyboard_up_and_down(map, key);
	if (k)
		adding_in_graphics(map);
	return (EXIT_SUCCESS);
}

void	init_game(t_map *map)
{
	map->line = 0;
	map->count_char = 0;
	map->collect = 0;
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