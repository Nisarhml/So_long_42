/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:51:23 by nihamila          #+#    #+#             */
/*   Updated: 2023/12/06 17:46:57 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (check_if_ber(argc, argv) == 0)
		exit(EXIT_FAILURE);
	init_game(&map);
	check_if_ber(argc, argv);
	count_line(&map, argv[1]);
	init_map(&map, argv[1]);
	copy_map(&map, argv[1]);
	check_valid_char(&map);
	count_valid_char(&map, 0, 0, 0);
	check_if_square(&map);
	check_if_closed(&map);
	check_valid_path(&map);
	check_after_fill(&map);
	player_position(&map);
	init_window(&map);
	adding_in_graphics(&map);
	mlx_hook(map.win_ptr, 2, 0, key_pressed, &map);
	mlx_hook(map.win_ptr, 17, 0, game_over, &map);
	mlx_loop_hook(map.mlx_ptr, adding_in_graphics, &map);
	mlx_loop(map.mlx_ptr);
	system("leaks so_long");
	free(map.mlx_ptr);
	return (EXIT_SUCCESS);
}
