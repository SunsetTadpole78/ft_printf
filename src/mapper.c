/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:16:21 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/16 15:11:34 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mapstr(t_data data, char *str)
{
	int	printed;
	int	len;

	if (!str)
	{
		str = "";
		if (!data.dot || data.size >= 6)
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
	if (data.dot && ((data.size > len) || (data.size == 0 && nbr == 0)))
		len = data.size;
	data.zero &= !(data.dot || data.minus);
	data.space &= !data.plus;
	printed -= nbr >= 0 && data.space;
	if (!data.minus && data.padding > 0 && !data.zero)
		printed += ft_printpadding(' ', data.padding - (len + printed
					+ (nbr < 0 || data.plus || data.space)));
	if (nbr < 0)
		printed += ft_printchar('-');
	else if (data.plus)
		printed += ft_printchar('+');
	if (data.zero && data.padding - printed > len)
		len = data.padding - printed;
	printed += ft_printpadding('0', len - ft_log(nbr, 10));
	if (len != 0)
		printed += ft_printnbr(ft_abs(nbr));
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

int	ft_mapunbr(t_data data, unsigned int nbr)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_log(nbr, 10);
	if (data.dot && ((data.size > len) || (data.size == 0 && nbr == 0)))
		len = data.size;
	data.zero &= !(data.dot || data.minus);
	if (!data.minus && data.padding > (len + printed) && !data.zero)
		printed += ft_printpadding(' ', data.padding - (len + printed));
	if (data.zero && data.padding > printed + len)
		len = data.padding - printed;
	printed += ft_printpadding('0', len - ft_log(nbr, 10));
	if (len != 0)
		printed += ft_printunbr(nbr);
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

int	ft_mapp(t_data data, void *p)
{
	int	printed;

	printed = 0;
	if (!data.minus)
		printed += ft_printpadding(' ', data.padding - ft_countp(p));
	printed += ft_printp(p);
	if (data.minus)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}

int	ft_maphexa(t_data data, unsigned long nbr)
{
	int	printed;
	int	len;

	printed = (nbr != 0) * data.hashtag * 2;
	len = ft_log(nbr, 16);
	if (data.dot && ((data.size > len) || (data.size == 0 && nbr == 0)))
		len = data.size;
	data.zero &= !(data.minus || data.dot);
	if (!data.minus && !data.zero && data.padding > printed + len)
		printed += ft_printpadding(' ', data.padding - (printed + len));
	if (nbr != 0 && data.hashtag)
		printed += ft_printchar('0') + ft_printchar(data.type);
	if (data.zero && data.padding > printed + len)
		len = data.padding - printed;
	printed += ft_printpadding('0', len - ft_log(nbr, 16));
	if (len != 0)
			printed += ft_printhexa(nbr, data.type);
	if (data.minus && data.padding > printed)
		printed += ft_printpadding(' ', data.padding - printed);
	return (printed);
}
