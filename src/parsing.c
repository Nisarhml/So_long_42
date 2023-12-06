/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:15:53 by nihamila          #+#    #+#             */
/*   Updated: 2023/12/06 17:50:30 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_ber(int argc, char **argv)
{
	int	fd;
	int	size;

	if (argc != 2)
	{
		ft_printf("invalid number of arguments\n");
		return (0);
	}
	size = ft_strlen(argv[1]);
	if (argv[1][size - 4] != '.' || argv[1][size - 3] != 'b'
		|| argv[1][size - 2] != 'e' || argv[1][size - 1] != 'r')
	{
		ft_printf("error, the file you choose is not a type .ber\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file not found\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	count_line(t_map *map, char *str)
{
	int		fd;
	char	*f_line;

	fd = open(str, O_RDONLY);
	f_line = get_next_line(fd);
	if (!f_line)
	{
		ft_printf("map, is empty\n");
		exit(EXIT_FAILURE);
	}
	map->line = 0;
	map->count_char = ft_strlen(f_line) - 1;
	while (f_line)
	{
		free(f_line);
		map->line++;
		f_line = get_next_line(fd);
	}
	close(fd);
}

void	init_map(t_map *map, char *str)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	map->full_map = malloc(sizeof(char *) * (map->line + 1));
	i = 0;
	map->full_map[i] = get_next_line(fd);
	while (i < map->line)
	{
		i++;
		map->full_map[i] = get_next_line(fd);
	}
	close(fd);
}

void	check_valid_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (++j < map->count_char)
		{
			if (map->full_map[i][j] != 'E' && map->full_map[i][j] != 'C'
				&& map->full_map[i][j] != 'P' && map->full_map[i][j] != '1'
				&& map->full_map[i][j] != '0')
			{
				ft_printf("invalid character, please check your map !\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
