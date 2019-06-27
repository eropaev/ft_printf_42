/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_probel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:11:17 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/27 01:19:33 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

void	probel(int width, int len)
{
	int	n;

	n = width - len;
	while (n-- > 0)
		ft_putchar(' ');
}

void	zeroo(int width, int len)
{
	int	n;

	n = width - len;
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
