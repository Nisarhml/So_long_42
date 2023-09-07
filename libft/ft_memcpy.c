/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:04:35 by nihamila          #+#    #+#             */
/*   Updated: 2023/03/30 17:49:56 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (size > 0)
	{
		*tmp1++ = *tmp2++;
		size--;
	}
	return (dest);
}
