/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 04:17:54 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

void		vivod_opchii(char **string, t_flagi *flag, va_list *arg)
{
	if (**string != '0' && ft_isdigit(**string))
		vivod_width(string, flag, arg);
	if (**string == '.')
		vivod_precision(string, flag, arg);
	if (**string == 'h' || **string == 'l' ||
	**string == 'j' || **string == 'z')
		vivod_length(string, flag, arg);
	if (**string == '#' || **string == '0' || **string == '-' || **string == '+'
			|| **string == ' ')
		vivod_flagi(string, flag, arg);
}

void		vivod_flagi(char **string, t_flagi *flag, va_list *arg)
{
	while (**string == '#' || **string == '0' ||
	**string == '-' || **string == '+' || **string == ' ')
	{
		if (**string == '#')
			flag->sharp = 1;
		if (**string == '0')
			flag->zero = 1;
		if (**string == '-')
			flag->minus = 1;
		if (**string == '+')
			flag->plus = 1;
		if (**string == ' ')
			flag->space = 1;
		(*string)++;
	}
	vivod_opchii(string, flag, arg);
}

void		vivod_width(char **string, t_flagi *flag, va_list *arg)
{
	int		width;

	width = 0;
	flag->width = ft_atoi(*string);
	while (ft_isdigit(**string))
		(*string)++;
	vivod_opchii(string, flag, arg);
}

void		vivod_precision(char **string, t_flagi *flag, va_list *arg)
{
	int		pres;

	pres = 0;
	while (**string == '.')
	{
		flag->prec = 1;
		(*string)++;
		flag->pres = ft_atoi(*string);
		while (ft_isdigit(**string))
			(*string)++;
	}
	vivod_opchii(string, flag, arg);
}

void		vivod_length(char **string, t_flagi *flag, va_list *arg)
{
	if (**string == 'h')
	{
		if (*(*string + 1) == 'h' && flag->e_length < 3)
			flag->e_length = hh;
		else if (flag->e_length < 2)
			flag->e_length = h;
	}
	if (**string == 'l')
	{
		if (*(*string + 1) == 'l' && flag->e_length < 5)
			flag->e_length = ll;
		else if (flag->e_length < 4)
			flag->e_length = l;
	}
	if (**string == 'j' && flag->e_length < 6)
		flag->e_length = j;
	if (**string == 'z')
		flag->e_length = z;
	if (flag->e_length)
		(*string)++;
	if (flag->e_length == hh || flag->e_length == ll)
		(*string)++;
	vivod_opchii(string, flag, arg);
}
