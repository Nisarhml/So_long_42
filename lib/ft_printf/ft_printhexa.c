/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:33:46 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/14 18:31:01 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int n, int d)
{
	int				i;
	char			*base;

	i = 0;
	if (d == 0)
		base = "0123456789abcdef";
	if (d == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = ft_printhexa((n / 16), d);
		ft_printhexa((n % 16), d);
	}
	else
	{
		ft_putchar(base[n % 16]);
	}
	return (i + 1);
}
