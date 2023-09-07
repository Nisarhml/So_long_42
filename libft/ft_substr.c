/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:02:37 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/04 17:05:08 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_str;
	size_t	i;
	size_t	j;

	i = start;
	len_str = 0;
	if (!s)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	while (s[i++] && len--)
		len_str++;
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < len_str)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
