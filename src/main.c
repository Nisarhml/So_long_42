/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:51:23 by nihamila          #+#    #+#             */
/*   Updated: 2023/08/31 22:54:57 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map map;
	
	check_if_ber(argc, argv);
	count_line(&map,argv[1]);
	init_map(&map, argv[1]);
	check_valid_char(&map);
	count_valid_char(&map, 0, 0, 0);
	check_if_square(&map);
	check_if_closed(&map);
	copy_map(&map, argv[1]);
	check_valid_path(&map);
	check_after_fill(&map);
	return (0);
}
