/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_probel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:11:17 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/28 00:56:08 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

void	probel(int width, int dlinna)
{
	int	n;

	n = width - dlinna;
	while (n-- > 0)
		ft_putchar(' ');
}

void	zeroo(int width, int dlinna)
{
	int	n;

	n = width - dlinna;
	while (n-- > 0)
		ft_putchar('0');
}

void	leviy_probel_shag(t_flagi *flag, int dlinna)
{
	if (flag->width && !flag->minus && !flag->zero)
		probel(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		zeroo(flag->width, dlinna);
}

int		undefined(char c, t_flagi *flag)
{
	int		dlinna;

	dlinna = 1;
	if (flag->width && !flag->zero && !flag->minus)
		put_space(flag->width, dlinna);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, dlinna);
	ft_putchar(c);
	if (flag->width && flag->minus)
		put_space(flag->width, dlinna);
	return (flag->width > dlinna ? flag->width : dlinna);
}
