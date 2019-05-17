/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 04:59:04 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/16 19:51:27 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_printf(const char *restrict a, ...)
{
	int			b;
	int			c;
	va_list		argument;

	va_start(argument, a);
	b = 0;
	c = 0;
	while (a[b] != '\0')
    {
		while(a[b] != '%' && a[b] != '\0')
	 	{
			ft_putchar(a[b]);
			c++;
			b++;
		}
		if (a[b] == '%')
		{
			b++;
			c += ft_ncounter(c, b, argument, a);
		}
		if (a[b] != '\0')
			b++;
	}
	va_end(argument);
	return(c);
}

