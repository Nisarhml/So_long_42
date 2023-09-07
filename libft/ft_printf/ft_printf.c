/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisarhamila <nisarhamila@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:39:46 by nihamila          #+#    #+#             */
/*   Updated: 2023/08/30 15:18:51 by nisarhamila      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(const char c)
{
	return (ft_strchr("scpdiuxX%", c) != 0);
}

static	int	ft_arg(const char str, va_list params, int count)
{
	if (str == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (str == 's')
		count += ft_putstr(va_arg(params, char *));
	else if (str == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(params, unsigned long));
	}
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(params, int));
	else if (str == 'u')
		count += ft_putnbr_unsigned(va_arg(params, unsigned int));
	else if (str == 'x')
		count += ft_printhexa(va_arg(params, unsigned int), 0);
	else if (str == 'X')
		count += ft_printhexa(va_arg(params, unsigned int), 1);
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

static	int	ft_final_arg(const char *str, va_list params)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%' && ft_check_arg(*(str + 1)))
		{
			str++;
			len = ft_arg(*str, params, len);
		}
		else
		{
			ft_putchar(*str);
			len ++;
		}
		str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	params;

	va_start(params, str);
	count = ft_final_arg(str, params);
	va_end (params);
	return (count);
}
