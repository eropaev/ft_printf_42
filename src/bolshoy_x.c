/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:43 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 05:13:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"
int		bolshoy_x(va_list *arg, t_flagi *flag)
{
	uintmax_t	hex;
	int			dlinna;

	hex = poluchit_unsign_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(hex, flag, 16);
	put_uint_left_space(flag, dlinna, hex, 2);
	if (!(flag->prec && !flag->precision && !hex))
		un_int_poluchit(hex, "0123456789ABCDEF", 16);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
