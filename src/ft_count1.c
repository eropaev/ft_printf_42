/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:30:45 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/16 20:30:33 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	get_flags (t_formats *strackt, int i, char *s)
{
	if (s[i] == '+' || s[i] == ' ' || s[i] == '-'m || s[i] == '#' || s[i] == '0')
	{
		if (s[i] == '+')
			strackt->plus = 1;
		if (s[i] == ' ')
			strackt->space = 1;
		if	(s[i] == '-')
			strackt->minus =1;
		if	(s[i] == '#')
			strackt->hash = 1;
		if	(s[i] == '0')
			strackt->zero = 1;
		i++;

	.
	.}
	return(i);
}

int	parsing(t_formats *strackt, int i, char *s)
{
	i = get_flags(strackt, i, s);

	return (i);
}

int	ft_ncounter(int i, va_list arg, const char *s)
{
	char		*counter;
	int			n;
	t_formats	*strackt;

	strackt = (t_formats*)malloc(sizeof(t_formats));

	i = parsing(strackt, i, s);

	n = 0;
	counter = "";
	if (s[i] == 's')
	{
		// counter = (va_arg(arg, char *));
		// if (!counter)
		// 	counter = "(null)";
		// ft_putstr(counter);
		// n += ft_strlen(counter);
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

