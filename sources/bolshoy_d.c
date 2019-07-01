/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:06:34 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:10:50 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int			bolshoy_d(va_list *arg, t_flagi *flag)
{
	long		nb;
	int			dlinna;

	nb = va_arg(*arg, long);
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
