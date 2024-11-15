/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:59:28 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 12:08:53 by lroussel         ###   ########.fr       */
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
		return ft_printstr("(null)", size);
	i = 0;
	while (str[i] && (size < 0 || i < size))
		i += ft_printchar(str[i]);
	return (i);
}

int	ft_printhexa(unsigned long value, char *base)
{
	int	printed;

	printed = 0;
	if (ft_strlen(base) != 16)
		return (0);
	if (value > 16)
	{
		printed += ft_printhexa(value / 16, base);
	}
	return (printed + ft_printchar(base[value % 16]));
}

int	ft_printp(void *p)
{
	int printed;

	if (!p)
		return (ft_printstr("(nil)", -1));
	printed = ft_printstr("0x", -1);
	printed += ft_printhexa((unsigned long)p, "0123456789abcdef");
	return (printed);
}

int	ft_printnbr(long int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		return ft_printstr("-2147483648", -1);
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

/*int	ft_printzeros(t_data data)
{
	int	printed;

	printed = 0;
	while (data.pointsize > 0)
	{
		printed += ft_printchar('0');
		data.pointsize--;
	}
	return (printed);
}

int	ft_printbefore(t_data *data, int *incr, int point)
{
	char	c;
	int	printed;

	if ((*data).zero || point)
		c = '0';
	else
		c = ' ';
	printed = 0;
	while (*incr > 0)
	{
		printed += ft_printchar(c);
		(*incr)--;
	}
	return (printed);
}

int	ft_printintbefore(t_data *data, int *incr, char *sign, int point)
{
	int	printed;
	int	signbefore;

	printed = 0;
	signbefore = (*data).zero || point;
	if (signbefore && (*sign == '+' || *sign == '-'))
		printed += ft_printchar(*sign);
	printed += ft_printbefore(data, incr, point);
	if (!signbefore && (*sign == '+' || *sign == '-'))
		printed += ft_printchar(*sign);
	*sign = ' ';
	return (printed);
}

int	ft_printpadding(t_padding padding, int type)
{
	int	printed;

	printed = 0;
	if (padding.type != type)
		return (0);
	while (padding.size > 0)
	{
		printed += ft_printchar(padding.c);
		padding.size--;
	}
	return (printed);
}*/
