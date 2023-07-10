/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:15:53 by nihamila          #+#    #+#             */
/*   Updated: 2023/07/10 16:36:23 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_ber(int argc, char **argv)
{
	int size;

	size = ft_strlen(argv[1]);
	
	if (argc < 2)
		return (0);
	if (argv[1][size - 4] != '.' || argv[1][size - 3] != 'b'
		|| argv[1][size - 2] != 'e' || argv[1][size - 1] != 'r')
		ft_printf("error, the file you choose is not a .ber\n");
	return (0);
}
