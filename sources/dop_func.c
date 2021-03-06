/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:05:56 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 04:56:47 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"

int			wide_char_dlinna(wchar_t c)
{
	int		dlinna;

	dlinna = 0;
	if (c <= 0x7F)
		dlinna = 1;
	else if (c <= 0x7FF)
		dlinna = 2;
	else if (c <= 0xFFFF)
		dlinna = 3;
	else
		dlinna = 4;
	return (dlinna);
}

int			wsd01(wchar_t *s)
{
	int		dlinna;
	int		i;

	dlinna = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		dlinna += wide_char_dlinna(s[i++]);
	return (dlinna);
}

int			wstr_dln(wchar_t *s, int n)
{
	int		dlinna;
	int		i;

	dlinna = 0;
	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (wide_char_dlinna(s[i]) > n)
			break ;
		n -= wide_char_dlinna(s[i]);
		dlinna += wide_char_dlinna(s[i++]);
	}
	return (dlinna);
}
