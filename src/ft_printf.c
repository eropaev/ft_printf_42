/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 04:59:04 by ieropaie          #+#    #+#             */
/*   Updated: 2019/04/30 02:55:54 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_printf(const char *restrict a, ...) // это вообще будет работать
{
	int	b; // ну переменные
	int	c;
	va_list argument; // структура

	va_start(argument, a); //инициализация
	b = 0; 
	c = 0;
	while ([b] != '\0') //итерация до стопера
    {
	while(a[b] != '%' && a[b] != '\0') // часный случай до %
	 {
            ft_putchar(a[b]);
			b++;
			c++;
        }
		if (a[b] == '%' && a[b] != '\0')
		{
			b++;
			c += ft_ncounter(c, b, argument, a);
			 // придумай функцию.....
		}
		if (a[b] != '\0')
			b++;
    }
	va_end(argument);
	return(c);

}
