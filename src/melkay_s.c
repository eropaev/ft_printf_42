/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 02:52:20 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/25 03:04:39 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_s(va_list *arg, t_flagi *flag)
{
	char	*string;
	int		dlinna;
	int		is_null;

	is_null = 0;
	if (flag->e_length == l)
		return (melkay_s(arg, flag));
	string = va_arg(*arg, char *);
	dlinna = (flag->precision) ? ft_strnlen(string, flag->precision) : ft_strlen(string);
	if (string == NULL)
	{
		is_null = 1;
		dlinna = (flag->precision) ? ft_strnlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		dlinna = 0;
	put_str_left_space(flag, dlinna);
	if (!(flag->prec && !flag->precision) && !is_null)
		ft_putnstr(string, dlinna);
	else if (is_null)
		ft_putnstr("(null)", dlinna);
	if (flag->minus && flag->width)
		put_space(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
