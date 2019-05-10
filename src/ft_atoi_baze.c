/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_baze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:30:25 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/06 18:04:28 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*ft_atoi_baze(long long znachenie, int baze)
{
	char	*str;
	char	*tab;
	int	flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (baze < 2 || baze > 16)
		return (str = "error");
	if (znachenie < 0 && baze == 10)
		flag = 1;
	str = itoa_napolnotel(tab, znachenie, baze, flag);
	return (str);
}
