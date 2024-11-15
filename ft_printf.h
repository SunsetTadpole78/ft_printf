/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:04:23 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 12:14:42 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>



#include <stdio.h>

typedef struct s_padding
{
	char	c;
	int	size;
	int	type;
	char	c2;
	int	size2;
	int	type2;
}	t_padding;

typedef struct s_data
{
	int	formatsize;
	char	type;
	int	minus;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
	int	padding;
	int	size;
}	t_data;

int	ft_printf(const char *format, ...);

int	ft_strlen(char *str);
unsigned int     ft_log(int long nb, int len);
int	ft_counthexa(unsigned long nbr);
int	ft_countp(void *p);
int	ft_atoi(char *nptr);

int	ft_printchar(char c);
int	ft_printstr(char *str, int size);
int	ft_printhexa(unsigned long value, char *base);
int	ft_printp(void *p);
int	ft_printnbr(long int nbr);
int	ft_printunbr(unsigned int nbr);

//int	ft_printspaces(t_data data, int type);
//int	ft_printzeros(t_data data);
//int	ft_printbefore(t_data *data, int *incr, int point);
//int	ft_printintbefore(t_data *data, int *incr, char *sign, int point);
int	ft_printpadding(char c, int times);

#endif
