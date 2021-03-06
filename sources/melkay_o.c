/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:57:44 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_o(va_list *arg, t_flagi *flag)
{
	uintmax_t		nb;
	int				dlinna;

	nb = poluchit_unsign_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(nb, flag, 8);
	if (flag->sharp && flag->pres > 0)
	{
		flag->pres--;
		dlinna--;
	}
	pst_uint_lspace(flag, dlinna, nb, 3);
	if (!(flag->prec && !flag->pres && !nb)
			&& !(flag->sharp && !nb))
		un_int_poluchit(nb, "012345678", 8);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
