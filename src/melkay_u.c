/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:58:01 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/28 00:27:06 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_u(va_list *arg, t_flagi *flag)
{
	uintmax_t		nb;
	int				len;

	nb = un_int_poluchit(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = un_int_poluchit_flag_dlinna(nb, flag, 10);
	postavit_uint_left_space(flag, len, nb, 0);
	if (!(flag->prec && !flag->precision && !nb))
		un_int_poluchit(nb, "0123456789", 10);
	if (flag->width && flag->minus)
		probel(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
