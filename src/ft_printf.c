/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 04:59:04 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/30 21:07:27 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *a, ...)
{
	int			b;  // порядковый номер
	int			c;  // ко-во считанных символов
	va_list		argument;

	va_start(argument, a);
	b = 0;
	c = 0;
	while (a[b] != '\0')
	{
		while (a[b] != '%' && a[b] != '\0')
		{
			ft_putchar(a[b]);
			c++;
			b++;
		}
		if (a[b] == '%')
		{
			b++;
			c += ft_ncounter(&b, argument, a);
		}
		if (a[b] != '\0')
			b++;
	}
	va_end(argument);
	return(c);
}

int		main()
{
	ft_printf("%-10.5d", 42);
	

	return (0);
}
