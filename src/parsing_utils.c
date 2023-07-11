/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:16:39 by nihamila          #+#    #+#             */
/*   Updated: 2023/07/11 17:22:29 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_valid_char(t_map *map, int c, int e, int p)
{
	int	i;
	int	j;

	i = - 1;
	while (++i < map->line)
	{
		j = - 1;
		while (++j < map->count_char)
		{
			if (map->full_map[i][j] == 'C')
				c++;
			if (map->full_map[i][j] == 'E')
				e++;
			if (map->full_map[i][j] == 'P')
				p++;
		}
	}
	if (e != 1 || p != 1 || c == 0)
	{
		ft_printf("invalid number of character\n");
		exit(EXIT_FAILURE);
	}
}

static	size_t	ft_strlen_mod(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	check_if_square(t_map *map)
{
	int		i;
	size_t	len;
	
	i = 0;
	len = ft_strlen_mod(map->full_map[0]);
	while (map->full_map[i])
	{
		if (ft_strlen_mod(map->full_map[i]) != len)
		{
			ft_printf("invalid map, check if it's a rectangle\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_if_closed(t_map *map)
{
	int	i;
	int	j;
	int	size_line;
	
	i = - 1;
	size_line = ft_strlen(map->full_map[0]) - 1;
	while (++i < size_line)
	{
		if (map->full_map[0][i] != '1'
			|| map->full_map[map->line - 1][i] != '1')
			{
				ft_printf("Map is not closed !\n");
				exit(EXIT_FAILURE);
			}
	}
	j = - 1;
	while (map->full_map[++j])
	{
		if (map->full_map[j][0] != '1'
			|| map->full_map[j][size_line - 1] != '1')
			{
				ft_printf("Map is not closed !\n");
				exit(EXIT_FAILURE);
			}
	}
}
