/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoia_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:19:44 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/15 23:16:47 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*itoa_napolnotel(char *tabula, long long znachenie, int baza, int flagi)
{
    unsigned long long hraniliche;
    int razmer;
    char    *str;       //

    razmer = 0;
    hraniliche = ft_abs(znachenie); //
    while (hraniliche /= baza)
    {
        razmer++;
    }
    razmer = razmer + flagi + 1;
    str = (char *)malloc(sizeof(char) * razmer + 1);
    str[razmer] = '\0';
    if (flagi == 1)
    {
        str[0] = '-';
    }
    while (razmer > flagi)
    {
        str[razmer - 1] = tabula[ft_abs(znachenie % baza)];
        razmer--;
        znachenie = znachenie / baza;
    }
    return(str);

}
