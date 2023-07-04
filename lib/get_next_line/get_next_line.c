/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:16:24 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/27 18:37:47 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), ft_strlen(stash) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (stash[i])
		new[j++] = stash[++i];
	free(stash);
	return (new);
}

char	*first_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i])
	{
		if (stash[i++] == '\n')
			break ;
	}
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_all(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*reader(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = free_all(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = reader(fd, stash);
	if (!stash)
		return (NULL);
	line = first_line(stash);
	stash = next_line(stash);
	if (line == '\0')
	{
		free(stash);
		free(line);
		return (0);
	}
	return (line);
}
