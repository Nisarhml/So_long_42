/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:54 by nihamila          #+#    #+#             */
/*   Updated: 2023/09/19 14:05:26 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbr(int n)
{
	int	count;

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

char	*ft_itoa(int n)
{
	int			i;
	long int	nbr;
	char		*str;

	i = ft_countnbr(n);
	nbr = n;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (nbr)
	{
		str[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (str);
}
