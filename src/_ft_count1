/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:30:45 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/30 21:23:21 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_flags (t_formats *strackt, int b, char *s) // принимает ( структру, коунтер, строку-структуру)
{
	if (s[b] == '+' || s[b] == ' ' || s[b] == '-' || s[b] == '#' || s[b] == '0')
	{
		if (s[b] == '+')
			strackt->plus = 1;
		if (s[b] == ' ')
			strackt->space = 1;
		if	(s[b] == '-')
			strackt->minus =1;
		if	(s[b] == '#')
			strackt->hash = 1;
		if	(s[b] == '0')
			strackt->zero = 1;
		i++;


	}
	return(i);
}

void	parsing(t_formats *strackt, int *b, char *s)
{
	*b = get_flags(strackt, *b, s);
	
	printf ("%d\n", strackt->minus);  // к проверква распечатка струкуры
	printf ("%d\n", strackt->with);
	printf ("%d\n", strackt->with_dot);
	
	*b = width(strackt, *b, s);
	*b = precision(strackt, *b, s);


}

int	ft_ncounter(int *b, va_list arg, char *s)
{
	char		*counter;
	int			n;
	t_formats	*strackt;
	// b = порядковый номер
	strackt = (t_formats*)malloc(sizeof(t_formats));

	parsing(strackt, b, s);

	n = 0;
	counter = "";
	return (n);
}
