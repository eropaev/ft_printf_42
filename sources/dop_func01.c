/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:22:54 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/28 00:38:34 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

void	poluchit_int(intmax_t nb)
{
	int			c;
	uintmax_t	n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n / 10 > 0)
		poluchit_int(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

int		poluchit_flagi_dlina(intmax_t nb, t_flagi *flag)
{
	int		dlinna;

	dlinna = poluchit_dlinna(nb);
	if (flag->precision > dlinna)
		dlinna += flag->precision - dlinna;
	if (flag->plus && nb >= 0)
		dlinna++;
	if (flag->space && !flag->plus && nb >= 0)
		dlinna++;
	if (nb < 0)
		dlinna++;
	if (flag->prec && !flag->precision && !nb)
		dlinna = flag->space ? 1 : 0;
	return (dlinna);
}

int		poluchit_dlinna(intmax_t nb)
{
	int			dlinna;
	uintmax_t	n;

	dlinna = 0;
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	while (n /= 10)
		dlinna++;
	return (dlinna + 1);
}

void	stavim_int_leviy_probel(t_flagi *flag, int dlinna, intmax_t nb)
{
	if (flag->space && !flag->plus && nb >= 0)
		ft_putchar(' ');
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->plus && nb >= 0 && dlinna != 0)
		ft_putchar('+');
	if (nb < 0 && dlinna != 0)
		ft_putchar('-');
	if (flag->zero && flag->width && !flag->minus && !flag->precision)
		zeroo(flag->width, dlinna);
	else if (flag->precision)
		zeroo(flag->precision, poluchit_dlinna(nb));
}
