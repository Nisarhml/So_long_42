/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:00:29 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/12/08 00:52:45 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_move(t_map *map, int i, int j)
{
	if (map->is_in_exit == 1)
		map->is_in_exit = 2;
	map->player_x = i;
	map->player_y = j;
	map->moves++;
	if (map->full_map[j][i] == 'E')
	{
		if (count_collect(map) != 0)
			map->is_in_exit = 1;
		else
		{
			ft_printf("\n Congrats, You found the ONE PIECE\n");
			game_over(map);
		}
	}
	map->full_map[j][i] = 'P';
}

static int	keyboard_up_and_down(t_map *map, int move, int i, int j)
{
	if (move == 1 || move == 125)
	{
		j++;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		if (map->is_in_exit == 2)
		{
			map->full_map[j - 1][i] = 'E';
			map->is_in_exit = 0;
		}
		else
			map->full_map[j - 1][i] = '0';
	}
	else if (move == 13 || move == 126)
	{
		j--;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		if (map->is_in_exit == 2)
		{
			map->full_map[j + 1][i] = 'E';
			map->is_in_exit = 0;
		}
		else
			map->full_map[j + 1][i] = '0';
	}
	ft_printf("Movement : %i\n", map->moves);
	return (1);
}

static int	keyboard_right_and_left(t_map *map, int move, int i, int j)
{
	if (move == 2 || move == 124)
	{
		i++;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		if (map->is_in_exit == 2)
		{
			map->full_map[j][i - 1] = 'E';
			map->is_in_exit = 0;
		}
		else
			map->full_map[j][i - 1] = '0';
	}
	else if (move == 0 || move == 123)
	{
		i--;
		if (map->full_map[j][i] == '1')
			return (0);
		init_move(map, i, j);
		if (map->is_in_exit == 2)
		{
			map->full_map[j][i + 1] = 'E';
			map->is_in_exit = 0;
		}
		else
			map->full_map[j][i + 1] = '0';
	}
	ft_printf("Movement : %i\n", map->moves);
	return (1);
}

int	key_pressed(int key, t_map *map)
{
	if (key == 53)
		game_over(map);
	else if (key == 13 || key == 126 || key == 1 || key == 125)
		keyboard_up_and_down(map, key, map->player_x, map->player_y);
	else if (key == 0 || key == 123 || key == 2 || key == 124)
		keyboard_right_and_left(map, key, map->player_x, map->player_y);
	adding_in_graphics(map, 0, 0);
	return (EXIT_SUCCESS);
}
