/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:56 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 05:51:57 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		lower_d(va_list *arg, t_flagi *flag)
{
	intmax_t		nb;
	int				dlinna;

	nb = get_type(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	dlinna = poluchit_flagi_(nb, flag);
	put_int_left_space(flag, dlinna, nb);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_int(nb);
	if (flag->minus && flag->width)
		put_space(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
