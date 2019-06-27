/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:30 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 04:44:44 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int			bolshoy_o(va_list *arg, t_flagi *flag)
{
	unsigned long int	nb;
	int					dlinna;

	nb = va_arg(*arg, unsigned long int);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(nb, flag, 8);
	if (flag->sharp && flag->precision > 0)
	{
		flag->precision--;
		dlinna--;
	}
	postavit_uint_left_space(flag, dlinna, nb, 3);
	if (!(flag->prec && !flag->precision && !nb) &&
			!(flag->sharp && !nb))
		un_int_poluchit(nb, "012345678", 8);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
