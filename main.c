/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:37:00 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 18:48:23 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int     main(void)
{
	char	format[] = "|%-185c|";

	printf("\n%i\n", ft_printf(format,'c'));
	printf("\nexpected: %i\n", printf(format,'c'));
}
