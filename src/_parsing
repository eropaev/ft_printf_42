/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:51:54 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/30 21:31:52 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_flags(t_formats *strackt, int b, char *s)
{
	if (s[b] == '+' || s[b] == ' ' || s[b] == '-' || s[b] == '#' || s[b] == '0')
	{
		if (s[b] == '+')
			strackt->plus = 1; // таким обазом поднимает флаги ( есть ли плюс в строке-структуре)
		if (s[b] == ' ')
			strackt->space = 1; // есть ли пробел итд
		if	(s[b] == '-')
			strackt->minus =1;
		if	(s[b] == '#')
			strackt->hash = 1;
		if	(s[b] == '0')
			strackt->zero = 1;
		b++;
	}
	return(b);
}

int width (t_formats *strackt, int b, char *s) // проверяем есть ли цыфры
{
	if (s[b] >= '0' && s[b] <= '9')
		strackt->with = ft_atoi(&s[b]); // переводм чаровое у интовое

		while (s[b] >= '0' && s[b] <= '9')
		{
		b++;
		}
	return (b);
}
int precision (t_formats *strackt, int b, char *s) //проверяем до точки
{
	if (s[b] == '.')
		strackt->with_dot = ft_atoi(&s[b]);

		while (s[b] >= '0' && s[b] <= '9')
		{
			b++;
		}
	return (b);

}
