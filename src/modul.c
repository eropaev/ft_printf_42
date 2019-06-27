/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 02:59:09 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 04:39:54 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		modul(va_list *arg, t_flagi *flag)
{
	int		dlinna;

	(void)arg;
	dlinna = 1;
	if (flag->width && !flag->zero && !flag->minus)
		probel(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		zeroo(flag->width, dlinna);
	ft_putchar('%');
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return (flag->width > dlinna ? flag->width : dlinna);
}
