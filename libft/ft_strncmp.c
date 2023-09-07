/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:52:13 by nihamila          #+#    #+#             */
/*   Updated: 2023/03/31 18:17:52 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	while (((*s1 == *s2) && (*s2 != '\0') && (0 < len)))
	{
		s1++;
		s2++;
		len--;
	}
	if (len == 0)
		return (0);
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
