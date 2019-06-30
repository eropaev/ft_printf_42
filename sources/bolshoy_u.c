/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:40 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/30 04:59:45 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		bolshoy_u(va_list *arg, t_flagi *flag)
{
	unsigned long int	nb;
	int					dlinna;

	nb = va_arg(*arg, unsigned long int);
	if (flag->prec)
		flag->zero = 0;
	dlinna = un_int_poluchit_flag_dlinna(nb, flag, 10);
	postavit_uint_left_space(flag, dlinna, nb, 0);
	if (!(flag->prec && !flag->precision && !nb))
		un_int_poluchit(nb, "0123456789", 10);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return ((flag->width) ? flag->width : dlinna);
}
