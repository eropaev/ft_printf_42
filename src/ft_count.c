/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:40:01 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/12 20:38:45 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_counter1 (int i, va_list arg, const char *s)
{
	char	*counter;
	int	n;

	n = 0;
	counter = "";
	if (s[i]) == 'd' || s[i] == 'i')
	{
		counter = ft_atoi_baze(va_arg(arg, int), 10);
		ft_putstr(counter);
		n += ft_strlen(counter);
	}
	if(s[i] == 'p')
	{
		ft_putstr("0x");
		counter = ft_atoi_baze(va_arg(arg, unsigned long long), 16);
		ft_putstr(counter);
		n += 2 + ft_strlen(counter)
	}
	return(n)

}
