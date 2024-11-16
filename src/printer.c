/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:59:28 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 20:57:28 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str, int size)
{
	int	i;

	if (!str)
		return (ft_printstr("(null)", size));
	i = 0;
	while (str[i] && (size < 0 || i < size))
		i += ft_printchar(str[i]);
	return (i);
}

int	ft_printhexa(unsigned long value, char type)
{
	int		printed;
	char	*base;
	
	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	printed = 0;
	if (ft_strlen(base) != 16)
		return (0);
	if (value >= 16)
		printed += ft_printhexa(value / 16, type);
	return (printed + ft_printchar(base[value % 16]));
}

int	ft_printp(void *p)
{
	int	printed;

	if (!p)
		return (ft_printstr("(nil)", -1));
	printed = ft_printstr("0x", -1);
	printed += ft_printhexa((unsigned long)p, 'x');
	return (printed);
}

int	ft_printnbr(long int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		return (ft_printstr("-2147483648", -1));
	if (nbr < 0)
	{
		res += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		res += ft_printnbr(nbr / 10);
	ft_printchar((nbr % 10) + '0');
	return (res + 1);
}

int	ft_printunbr(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr > 9)
		res += ft_printunbr(nbr / 10);
	ft_printchar((nbr % 10) + '0');
	return (res + 1);
}

int	ft_printpadding(char c, int times)
{
	int	printed;

	printed = 0;
	while (times > 0)
	{
		printed += ft_printchar(c);
		times--;
	}
	return (printed);
}
