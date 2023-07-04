/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:55:03 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/07 18:56:36 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
			continue ;
		}
		i++;
	}
	return (word);
}

int	ft_len_word(const char *str, char c, int start)
{
	int		i;
	int		len_word;

	i = start;
	len_word = 0;
	while (str[i] && str[i] != c)
	{
		len_word++;
		i++;
	}
	return (len_word);
}

char	*cpy_word(const char *str, char c, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = start;
	j = 0;
	len = ft_len_word(str, c, start);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (str[i] && str[i] != c)
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			split[j++] = cpy_word(s, c, i);
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	split[j] = 0;
	return (split);
}
