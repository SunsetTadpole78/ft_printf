/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:04:23 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 21:31:51 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int		formatsize;
	char	type;
	int		minus;
	int		zero;
	int		dot;
	int		hashtag;
	int		space;
	int		plus;
	int		padding;
	int		size;
	int		star;
}	t_data;

int				ft_printf(const char *format, ...);

//Mapper
int				ft_mapstr(t_data data, char *str);
int				ft_mapchar(t_data data, char c);
int				ft_mapnbr(t_data data, long int nbr);
int				ft_mapunbr(t_data data, unsigned int nbr);
int				ft_mapp(t_data data, void *p);
int				ft_maphexa(t_data data, unsigned long nbr);

int				ft_strlen(char *str);
unsigned int	ft_log(int long nb, int len);
int				ft_counthexa(unsigned long nbr);
int				ft_countp(void *p);
int				ft_mini_atoi(const char *nptr);
long int		ft_abs(long int nbr);

int				ft_printchar(char c);
int				ft_printstr(char *str, int size);
int				ft_printhexa(unsigned long value, char type);
int				ft_printp(void *p);
int				ft_printnbr(long int nbr);
int				ft_printunbr(unsigned int nbr);

int				ft_printpadding(char c, int times);

#endif
