/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:31 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		bolshoy_s(va_list *arg, t_flagi *flag)
{
	wchar_t		*string;
	int			dlinna;
	int			is_null;

	is_null = 0;
	string = va_arg(*arg, wchar_t*);
	dlinna = (flag->pres) ? wstr_dln(string, flag->pres) : wsd01(string);
	if (string == NULL)
	{
		is_null = 1;
		dlinna = (flag->pres) ? ft_strnlen("(NULL)", flag->pres) : 6;
	}
	if (flag->prec && flag->pres == 0)
		dlinna = 0;
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		zeroo(flag->width, dlinna);
	if (!(flag->prec && flag->pres == 0) && is_null == 0)
		ft_putnwstr(string, dlinna);
	else if (is_null == 1)
		ft_putnstr("(NULL)", dlinna);
	if (flag->minus && flag->width)
		probel(flag->width, dlinna);
	return ((flag->width) > dlinna ? flag->width : dlinna);
}
