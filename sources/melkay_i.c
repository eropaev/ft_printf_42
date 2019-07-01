/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:57:05 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_i(va_list *arg, t_flagi *flag)
{
	intmax_t		nb;
	int				dlinna;

	nb = poluchit_tip(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = poluchit_flagi_dlina(nb, flag);
	stavim_int_leviy_probel(flag, dlinna, nb);
	if (!(flag->prec && flag->pres == 0 && nb == 0))
		poluchit_int(nb);
	if (flag->minus && flag->width)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
