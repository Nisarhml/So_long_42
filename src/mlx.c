/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:51:49 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/09/06 14:56:19 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->player, y * 64, x * 64);
}

