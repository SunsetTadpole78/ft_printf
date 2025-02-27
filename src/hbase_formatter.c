/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbase_formatter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:16:21 by lroussel          #+#    #+#             */
/*   Updated: 2025/02/27 18:22:56 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_hexa(t_data data, unsigned long nbr, int fd)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_log(nbr, 16);
	if (data.dot && ((data.elsize > len) || (data.elsize == 0 && nbr == 0)))
		len = data.elsize;
	data.zero &= !(data.minus || data.dot);
	if (!data.minus && !data.zero && data.padding > printed + len)
		printed += ft_print_char(' ', data.padding - (printed + len), fd);
	printed += ft_print_char('0', nbr != 0 && data.hashtag, fd);
	printed += ft_print_char(data.type, nbr != 0 && data.hashtag, fd);
	if (data.zero && data.padding > printed + len)
		len = data.padding - printed;
	printed += ft_print_char('0', len - ft_log(nbr, 16), fd);
	if (len != 0)
		printed += ft_print_hexa(nbr, data.type, fd);
	if (data.minus && data.padding > printed)
		printed += ft_print_char(' ', data.padding - printed, fd);
	return (printed);
}

int	format_pointer(t_data data, void *p, int fd)
{
	int	printed;

	printed = 0;
	if (!data.minus)
		printed += ft_print_char(' ', data.padding - ft_pointerlen(p), fd);
	printed += ft_print_pointer(p, fd);
	if (data.minus)
		printed += ft_print_char(' ', data.padding - printed, fd);
	return (printed);
}
