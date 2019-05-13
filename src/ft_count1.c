/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:30:45 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/12 20:43:13 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_counter2(int i, va_list arg, const char *s)
{
	char	*counter;
	int	n;

	n = 0;
	counter = "";
	if (s[i] == 'o')
	{
		counter = ft_atoi_baze(va_arg(arg, unsigned int), 8);
		ft_putstr(counter);
		n += ft_strlen(counter);
	}
	if (s[i] == 'u')
	{
		counter = ft_atoi_baze(va_arg(arg, unsigned int), 10);
		ft_putstr(counter);
		n += ft_strlen(counter);
	}
	if (s[i] == 'x')
	{
		counter = ft_atoi_baze(va_arg(arg, unsigned int), 16);
		ft_putstr(counter);
		n += ft_strlen(counter);
	}
	return (n);
}
int	ft_ncounter3(int i, const char *s)
{
	int		n;

	n = 0;
	if (s[i] == '%')
	{
		ft_putchar('%');
		n++;
	}
	return (n);
}

int	ft_ncounter(int i, va_list arg, const char *s)
{
	char	*counter;
	int		n;

	n = 0;
	counter = "";
	if (s[i] == 's')
	{
		counter = (va_arg(arg, char *));
		if (!counter)
			counter = "(null)";
		ft_putstr(counter);
		n += ft_strlen(counter);
	}
	if (s[i] == 'c')
	{
		ft_putchar(va_arg(arg, int));
		n++;
	}
	n += ft_ncounter1(i, arg, s);
	n += ft_ncounter2(i, arg, s);
	n += ft_ncounter3(i, s);
	return (n);
}

