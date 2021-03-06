/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:58:06 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_x(va_list *arg, t_flagi *flag)
{
	uintmax_t		hex;
	int				dlinna;

	hex = poluchit_unsign_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(hex, flag, 16);
	pst_uint_lspace(flag, dlinna, hex, 1);
	if (!(flag->prec && !flag->pres && !hex))
		un_int_poluchit(hex, "0123456789abcdef", 16);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
