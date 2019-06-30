/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:12:21 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 05:51:57 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

void	un_int_poluchit(uintmax_t nb, char *string, int base)
{
	int	c;

	if (nb / base > 0)
		un_int_poluchit(nb / base, string, base);
	c = nb % base;
	write(1, &string[c], 1);
}

int		un_int_poluchit_dlin(uintmax_t nb, int base)
{
	int		dlinna;

	dlinna = 0;
	while (nb /= base)
		dlinna++;
	return (dlinna + 1);
}

int		un_int_poluchit_flag_dlinna(uintmax_t nb, t_flagi *flag, int base)
{
	int		dlinna;

	dlinna = un_int_poluchit_dlin(nb, base);
	if (flag->precision > dlinna)
		dlinna += flag->precision - dlinna;
	if (flag->sharp)
	{
		if (base == 16 && nb > 0)
			dlinna += 2;
		if (base == 8 && nb > 0)
			dlinna++;
	}
	if (flag->prec && !flag->precision && !nb)
		dlinna = (flag->sharp && base == 8) ? 1 : 0;
	return (dlinna);
}

void	postavit_uint_left_space(t_flagi *flag, int dlinna, uintmax_t nb, int type)
{
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->sharp || type == 4)
	{
		if ((type == 1 && dlinna != 0 && nb > 0) || type == 4)
			ft_putstr("0x");
		if ((type == 2 && dlinna != 0 && nb > 0))
			ft_putstr("0X");
		if (type == 3)
			ft_putstr("0");
	}
	if (flag->zero && flag->width && !flag->minus && !flag->precision)
		zeroo(flag->width, dlinna);
	else if (flag->precision)
	{
		if (type == 1 || type == 2 || type == 4)
			zeroo(flag->precision, un_int_poluchit_dlin(nb, 16));
		if (type == 3)
			zeroo(flag->precision, un_int_poluchit_dlin(nb, 8));
		if (type == 0)
			zeroo(flag->precision, un_int_poluchit_dlin(nb, 10));
		if (type == 5)
			zeroo(flag->precision, un_int_poluchit_dlin(nb, 2));
	}
}
