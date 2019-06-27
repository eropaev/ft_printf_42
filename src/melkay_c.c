/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melkay_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:56:53 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 05:51:57 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int			meklay_c(va_list *arg, t_flagi *flag)
{
	unsigned char	c;
	int				dlinna;

	dlinna = 1;
	if (flag->e_length == l)
		return (bolshoy_c(arg, flag));
	c = (unsigned char)va_arg(*arg, int);
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		zeroo(flag->width, dlinna);
	write(1, &c, 1);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return (flag->width > dlinna ? flag->width : dlinna);
}
