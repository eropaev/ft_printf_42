/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:43 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/30 01:50:57 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		bolshoy_x(va_list *arg, t_flagi *flag)
{
	uintmax_t	heximal;
	int			dlinna;

	heximal = poluchit_unsign_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(heximal, flag, 16);
	put_uint_left_space(flag, dlinna, heximal, 2);
	if (!(flag->prec && !flag->precision && !heximal))
		un_int_poluchit(heximal, "0123456789ABCDEF", 16);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
