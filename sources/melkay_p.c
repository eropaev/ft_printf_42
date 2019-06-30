/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:57:47 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 19:21:52 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		melkay_p(va_list *arg, t_flagi *flag)
{
	void		*ptr;
	uintmax_t	nb;
	int			dlinna;

	ptr = va_arg(*arg, void*);
	nb = (unsigned long)ptr;
	dlinna = un_int_poluchit_flag_dlinna(nb, flag, 16);
	if (!flag->sharp)
		dlinna += 2;
	postavit_uint_left_space(flag, dlinna, nb, 4);
	if (!(flag->prec && !flag->precision && !nb))
		un_int_poluchit(nb, "0123456789abcdef", 16);
	if (flag->minus && flag->width)
		probel(flag->width, dlinna);
	return ((flag->width > dlinna) ? flag->width : dlinna);
}
