/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:15:11 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/14 18:23:32 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int					i;
	char				*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		i = ft_putptr(n / 16);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
	return (i + 1);
}
