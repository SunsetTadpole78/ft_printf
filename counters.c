/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:13:04 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 11:56:56 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int     ft_countdigits(long int n)
{
	int     count;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	count = 0;
	while (n / 10 != 0 || n % 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

unsigned int	ft_log(int long nb, int len)
{
	if (nb < 0)
		nb = -nb;
	if (nb < len)
		return (1);
	return (1 + ft_log(nb / len, len));
}

int	ft_counthexa(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr > 16 || nbr % 16 != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_countp(void *p)
{
	if (!p)
		return (5);
	return (ft_counthexa((unsigned long)p) + 2);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	short int	s;
	int			result;

	i = 0;
	s = 1;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	nptr = nptr + i;
	return (result * s);
}
