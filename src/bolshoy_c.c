/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bolshoy_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:03:03 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 01:05:30 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int		bolshoy_c(va_list *arg, t_flagi *flag)
{
	wchar_t			c;
	int				dlinna;

	c = (wchar_t)va_arg(*arg, wint_t);
	dlinna = wchar_dlinna(c);
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		zeroo(flag->width, dlinna);
	ft_putwchar(c);
	if (flag->width && flag->minus)
		probel(flag->width, dlinna);
	return (flag->width > dlinna ? flag->width : dlinna);
}
