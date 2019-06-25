/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 04:59:04 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/24 16:19:18 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtftprintf.h"
/*
принимает структуру созданную в хедере t_flagi с указателем на flag
резетит флаги выставляя на 0
*/
void		sbros_flagov(t_flagi *flag)
{
		flag->e_length = 0;
		flag->minus = 0;
		flag->plus = 0;
		flag->prec = 0;
		flag->precision = 0;
		flag->sharp = 0;
		flag->space = 0;
		flag->width = 0;
		flag->zero = 0;
}
/*
функция выставления спецификаторов
принимает формат из printf, структуру флагов,
*/
int		spechificator(char **format, t_flagi *flag,va_list *arg)
{
	static int	(*form[])(va_list*, t_flagi*) = {melkay_d, melkay_i,
			melkay_o, melkay_u, melkay_x, melkay_c, melkay_s,
			melkay_p, bolshoy_s, bolshoy_d, bolshoy_o, bolshoy_u, bolshoy_x, bolshoy_c
			modul, 0 };
static char spechifier [] = {'d', 'i', 'o', 'u', 'x', 'c', 's', 'p', 'D', 'O',
'U', 'X', 'C', '%', 0};

int			i;
int			vivod;

i = 0;

while (spechifier[i] != **format && spechifier[i])
		i++;
	if (**format != '\0' && spechifier[i] == **format)
	{
		vivod = form[i](arg, flag);
		(*format)++;
		return (spechifier);
	}
	if (**format != '\0')
	{
		(*format)++;
		return (undefined(*(*format - 1), flag));
	}
	return (0);
}
/*
парсинг, работа парсера
*/
int		parsser(char **format, t_flagi *flag, va_list *arg)
{
int		vivod;

vivod = 0;
	while (**format)
	{
		if (**format == '%')
		{
			sbros_flagov(flag);
			(*format)++;
			spechificator(format, flag, arg);
			vivod += spechificator(format, flag, arg);
		}
		else if (**format != '\0')
		{
			ft_putchar(**format);
			(*format)++;
			vivod++;
		}
	}
	return(vivod);
}

int		ft_printf(const char *format, ...) // основной вывод
{
	va_list		arg;
	t_flagi		*flag;
	int			vivod;

	vivod = 0;
	flag = ft_memalloc(sizeof(t_flagi));
	va_start(arg, format);
	vivod = parser((char**)&format, flag, &arg);
	va_end(arg);
	ft_memdel((void**)&flag);
	return (vivod);
}







// int		main()
// {
// 	ft_printf("%-10.5d", 42);


// 	return (0);
// }
