/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:59:36 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 21:33:07 by lroussel         ###   ########.fr       */
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

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
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
			data->padding = ft_abs(ft_mini_atoi((char *)c));
		else if (data->dot && data->size == 0)
		{
			data->size = ft_abs(ft_mini_atoi((char *)c));
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
		*printed += (ft_maphexa(data, va_arg(args, unsigned int)));
	else if (data.type == '%')
		*printed += (ft_printchar('%'));
	return (data);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	printed;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i+= (format_map(format + i + 1, args, &printed).formatsize + 1);
		else
			printed += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
