/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:31 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/04 18:13:53 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dest[i])
		i++;
	j = i;
	while (src[i - j] && (i + 1) < size)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < size)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
