/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:58:01 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_u(va_list *arg, t_flagi *flag)
{
	uintmax_t		nb;
	int				len;

	nb = poluchit_unsign_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = un_int_poluchit_flag_dlinna(nb, flag, 10);
	pst_uint_lspace(flag, len, nb, 0);
	if (!(flag->prec && !flag->pres && !nb))
		un_int_poluchit(nb, "0123456789", 10);
	if (flag->width && flag->minus)
		probel(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
