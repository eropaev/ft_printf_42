/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   po_tipu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 03:07:40 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 04:40:40 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

intmax_t		poluchit_tip(va_list *arg, t_flagi *flag)
{
	intmax_t		vivod;

	vivod = va_arg(*arg, intmax_t);
	if (flag->e_length == hh)
		return (signed char)vivod;
	if (flag->e_length == h)
		return (short)vivod;
	if (flag->e_length == l)
		return (long)vivod;
	if (flag->e_length == ll)
		return (long long)vivod;
	if (flag->e_length == j)
		return (vivod);
	if (flag->e_length == z)
		return (size_t)vivod;
	return (int)vivod;
}

uintmax_t		poluchit_unsign_tip(va_list *arg, t_flagi *flag)
{
	uintmax_t		vivod;

	vivod = va_arg(*arg, uintmax_t);
	if (flag->e_length == hh)
		return (unsigned char)vivod;
	if (flag->e_length == h)
		return (unsigned short)vivod;
	if (flag->e_length == l)
		return (unsigned long)vivod;
	if (flag->e_length == ll)
		return (unsigned long long)vivod;
	if (flag->e_length == j)
		return (vivod);
	if (flag->e_length == z)
		return (size_t)vivod;
	return (unsigned int)vivod;
}
