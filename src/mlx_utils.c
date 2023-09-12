/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:51:37 by nisarhamila       #+#    #+#             */
/*   Updated: 2023/09/12 16:36:01 by nisarhamila      ###   ########.fr       */
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
