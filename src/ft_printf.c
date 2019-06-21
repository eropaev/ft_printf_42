/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 04:59:04 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/20 19:41:42 by ieropaie         ###   ########.fr       */
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
*/
int		spechificator(char *format, t_flagi *flag,va_list *arg)
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
		/* code */
	}

}


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
