/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:59:36 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 16:14:49 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_getspaces(const char *format)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (format[i] == '+' || format[i] == '-')
	{
		if (format[i] == '-')
			sign = -1;
		i++;
	}
	while (format[i] >= '0' && format[i] <= '9')
	{
		res = res * 10 + (format[i] - '0');
		i++;
	}
	return (sign * res);
}

int	ft_getpointsize(const char *format)
{
	int	i;
	int	size;

	i = 0;
	while (format[i] == '+' || format[i] == '-'
		|| (format[i] >= '0' && format[i] <= '9'))
		i++;
	if (format[i] != '.')
		return (-1);
	i++;
	size = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		size = size * 10 + (format[i] - '0');
		i++;
	}
	return (size);
}

void	ft_update_padding(int *size, int len)
{
	if (*size - len <= 0)
		*size = 0;
	else
		*size -= len;
}

long int	ft_abs(long int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_mapstr(t_data data, char *str)
{
	int	printed;
	int	len;
	if (!str)
	{
		if (data.dot && data.size < 6)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (data.dot && data.size < len)
		len = data.size;
	printed = 0;
	if (!data.minus)
		printed += ft_printpadding(' ', data.padding - len);	
	printed += ft_printstr(str, len);
	if (data.minus)
		printed += ft_printpadding(' ', data.padding - len);
	return (printed);
}

int	ft_mapchar(t_data data, char c)
{
	int	printed;

	printed = 0;
	if (!data.minus)
		printed += ft_printpadding(' ', data.padding - 1);
	printed += ft_printchar(c);
	if (data.minus)
		printed += ft_printpadding(' ', data.padding - 1);
	return (printed);
}

int	ft_mapnbr(t_data data, long int nbr)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_log(nbr, 10);

	if (data.dot && data.size > len)
		len = data.size;

	if (data.dot && data.size == 0 && nbr == 0)
		len = 0;

	if ((data.dot || data.minus) && data.zero)
		data.zero = 0;
	if (data.plus && data.space)
		data.space = 0;

	if (nbr >= 0 && data.space)
		printed += ft_printchar(' ');
	if (!data.minus && data.padding > 0 && !data.zero)
		printed += ft_printpadding(' ', data.padding - (len + printed + (nbr < 0 || data.plus || (nbr >= 0 && data.space))));
	if (nbr < 0)
		printed += ft_printchar('-');
	else if (data.plus)
		printed += ft_printchar('+');
	if (data.zero && data.padding - printed > len)
		len = data.padding - printed;

	printed += ft_printpadding('0', len - (ft_log(nbr, 10)));
	if (len != 0)
		printed += ft_printnbr(ft_abs(nbr));
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

int	ft_mapunbr(t_data data, unsigned int nbr)
{
	int printed;
	int len;

	len = ft_log(nbr, 10);
	printed = 0;
	if (data.dot && data.size > len)
		len = data.size;
	if (data.dot && data.size == 0 && nbr == 0)
		len = 0;
	if ((data.dot || data.minus) && data.zero)
		data.zero = 0;
	if (!data.minus && data.padding > len + printed && !data.zero)
		printed += ft_printpadding(' ', data.padding - (len + printed));
	if (data.zero && data.padding - printed > len)
		len = data.padding;
	printed += ft_printpadding('0', len - (ft_log(nbr, 10)));
	if (len != 0)
		printed += ft_printunbr(nbr);
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

int	ft_mapp(t_data data, void *p)
{
	int	printed;
	int	len;

	len = ft_countp(p);
	printed = 0;
	if (!data.minus)
		printed += ft_printpadding(' ', data.padding - len);
	printed += ft_printp(p);
	if (data.minus)
		printed += ft_printpadding(' ', data.padding - len);
	return (printed);
}

int	ft_maphexa(t_data data, unsigned long nbr)
{
	int printed;
	int len;

	len = ft_log(nbr, 16);
	printed = ((nbr != 0) * data.hashtag * 2);
	if (data.dot && data.size > len)
		len = data.size;
	if (data.dot && data.size == 0 && nbr == 0)
		len = 0;
	if ((data.minus || data.dot) && data.zero)
		data.zero = 0;
	if (!data.minus && !data.zero && data.padding > printed + len)
		printed += ft_printpadding(' ', data.padding - (printed + len));
	if (nbr != 0 && data.space)
	{
		if (data.type == 'x')
			printed += ft_printstr("0x", 2);
		else
			printed += ft_printstr("0X", 2);
	}
	if (data.zero && data.padding - printed > len)
		len = data.padding - printed;
	printed += ft_printpadding('0', len - (ft_log(nbr, 16)));
	if (data.type == 'x' && len != 0)
		printed += ft_printhexa(nbr, "0123456789abcdef");
	else if (len != 0)
		printed += ft_printhexa(nbr, "0123456789ABCDEF");
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

void	init_flags(t_data *data)
{
	data->plus = 0;
	data->space = 0;
	data->hashtag = 0;
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->padding = 0;
	data->size = 0;
}

void fix(t_data *data)
{
	if (data->padding < 0)
		data->minus = 1;
	if (data->padding < 0)
		data->padding *= -1;
	if (data->size < 0)
		data->dot = 0;
}
void	update_flags(const char *c, t_data *data, va_list args)
{
	if (*c == '-')
		data->minus = 1;
	else if (*c == '0' && !data->dot && data->padding == 0)
		data->zero = 1;
	else if (*c == '.')
		data->dot = 1;
	else if (*c == '#')
		data->hashtag = 1;
	else if (*c == ' ')
		data->space = 1;
	else if (*c == '+')
		data->plus = 1;
	else if (*c == '*' && !data->dot && data->padding == 0)
		data->padding = va_arg(args, int);
	else if (*c >= '0' && *c <= '9')
	{
		if (!data->dot && data->padding == 0)
			data->padding = ft_abs(ft_atoi((char *)c));
		else if (data->dot && data->size == 0)
		{
			data->size = ft_abs(ft_atoi((char *)c));
			data->dot = 1;
		}
	}
	else if (*c == '*' && data->dot && data->size == 0)
		data->size = va_arg(args, int);
	fix(data);
}

t_data	init_data(const char *format, va_list args)
{
	const char types[] = "cipdsxXu%";
	int	i;
	t_data	data;

	i = 0;
	init_flags(&data);
	while (!ft_strchr(types, format[i]))
	{
		update_flags(format + i, &data, args);
		i++;
	}
	//printf("!\nt %c\np %i\nsp %i\nh %i\nm %i\nz %i\nd %i\np %i\ns %ia!", data.type, data.plus, data.space, data.hashtag, data.minus, data.zero, data.dot, data.padding, data.size);
	data.type = format[i];
	data.formatsize = i;
	return (data);
}

t_data	format_map(const char *format, va_list args, int *printed)
{
	t_data	data;

	data = init_data(format, args);
	if (data.type == 'c')
		*printed += (ft_mapchar(data, va_arg(args, int)));
	else if (data.type == 's')
		*printed += (ft_mapstr(data, va_arg(args, char *)));
	else if (data.type == 'i' || data.type == 'd')
		*printed += (ft_mapnbr(data, va_arg(args, int)));
	else if (data.type == 'u')
		*printed += (ft_mapunbr(data, va_arg(args, unsigned int)));
	else if (data.type == 'p')
		*printed += (ft_mapp(data, va_arg(args, void *)));
	else if (data.type == 'x' || data.type == 'X')
		*printed += (ft_maphexa(data, va_arg(args, unsigned long)));
	else if (data.type == '%')
		*printed += (ft_printchar('%'));
	return (data);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	printed;
	t_data	data;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			data = format_map(format + i + 1, args, &printed);
			i += data.formatsize + 1;
		} else
		{
			write(1, &format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
