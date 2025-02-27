/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:09:11 by lroussel          #+#    #+#             */
/*   Updated: 2025/02/27 18:13:53 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	format_switcher(const char *format, va_list args, int *printed, int fd)
{
	t_data	data;

	data = init_data(format, args);
	if (data.type == 'c')
		*printed += (format_char(data, va_arg(args, int), fd));
	else if (data.type == 's')
		*printed += (format_str(data, va_arg(args, char *), fd));
	else if (ft_strchr("id", data.type))
		*printed += (format_int(data, va_arg(args, int), fd));
	else if (data.type == 'u')
		*printed += (format_unsigned_int(data, va_arg(args, unsigned int), fd));
	else if (data.type == 'p')
		*printed += (format_pointer(data, va_arg(args, void *), fd));
	else if (ft_strchr("xX", data.type))
		*printed += (format_hexa(data, va_arg(args, unsigned int), fd));
	else if (data.type == '%')
		*printed += (ft_print_char('%', 1, fd));
	return (data);
}
