/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:37:00 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 16:39:13 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int     main(void)
{
	char	format[] = "|%-*.121X|";

	printf("\n%i\n", ft_printf(format, 4188073291u));
	//printf("\nexpected: %i\n", printf(format, 4188073291u));
}
