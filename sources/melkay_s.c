/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 02:52:20 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
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
	dlinna = (flag->pres)
	? ft_strnlen(string, flag->pres) : ft_strlen(string);
	if (string == NULL)
	{
		is_null = 1;
		dlinna = (flag->pres) ? ft_strnlen("(null)", flag->pres) : 6;
	}
	if (flag->prec && flag->pres == 0)
		dlinna = 0;
	leviy_probel_shag(flag, dlinna);
	if (!(flag->prec && !flag->pres) && !is_null)
		ft_putnstr(string, dlinna);
	else if (is_null)
		ft_putnstr("(null)", dlinna);
	if (flag->minus && flag->width)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
