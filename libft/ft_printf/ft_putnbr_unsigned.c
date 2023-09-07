/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:13 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/17 14:33:54 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnbr_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		count ++;
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	i;

	i = ft_countnbr_unsigned(nb);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb %= 10);
	}
	else
		ft_putchar (nb + 48);
	return (i);
}
