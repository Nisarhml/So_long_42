/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamila <nihamila@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:04 by nihamila          #+#    #+#             */
/*   Updated: 2023/04/17 14:34:33 by nihamila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
# include <stdlib.h>
# include <stdarg.h>

int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long n);
size_t	ft_strlen(const char *str);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *str, int c);
int		ft_printhexa(unsigned int n, int d);

#endif
