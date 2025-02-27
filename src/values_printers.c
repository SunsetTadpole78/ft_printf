/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:59:28 by lroussel          #+#    #+#             */
/*   Updated: 2025/02/27 18:31:35 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int times, int fd)
{
	int	i;

	i = 0;
	while (i < times)
	{
		write(fd, &c, 1);
		i++;
	}
	return (i);
}

int	ft_print_str(char *str, int size, int fd)
{
	int	i;

	if (!str)
		return (ft_print_str("(null)", size, fd));
	i = 0;
	while (str[i] && (size < 0 || i < size))
		i += ft_print_char(str[i], 1, fd);
	return (i);
}

int	ft_print_unsigned_int(unsigned int nbr, int fd)
{
	int	res;

	res = 0;
	if (nbr > 9)
		res += ft_print_unsigned_int(nbr / 10, fd);
	ft_print_char((nbr % 10) + '0', 1, fd);
	return (res + 1);
}

int	ft_print_hexa(unsigned long value, char type, int fd)
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
		printed += ft_print_hexa(value / 16, type, fd);
	return (printed + ft_print_char(base[value % 16], 1, fd));
}

int	ft_print_pointer(void *p, int fd)
{
	int	printed;

	if (!p)
		return (ft_print_str("(nil)", 5, fd));
	printed = ft_print_str("0x", 2, fd);
	printed += ft_print_hexa((unsigned long)p, 'x', fd);
	return (printed);
}
