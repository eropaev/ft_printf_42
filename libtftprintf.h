/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtftprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:58:41 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/23 04:49:02 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTFTPRINTF_H
# define LIBTFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "../libtft/libft.h"

typedef struct		s_flagi // инициалищация структуры в нее засунуть все поднятые флаги
{
	int				precision;
	int				prec;
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
	int				width;
	enum		// спецификаторы через enumerator list первое значение 0 и дальше
	{
		none, // int или un.int
		h,	// то же - но принудительно приводится к sh. int ии un. s. int
		hh,	 // то же - но к sign. char or unsign. char
		l, // long int or insign. long int
		ll, // long long int or uns.
		j,	// intmax or uintmax
		z	// size_t или эквивалент
	}				e_length;
}					t_flagi;

// функции спецификаторов
int					ft_printf(const char *format, ...);
int					parsser(char **format, t_flagi *flag, va_list *arg);
int					spechificator(char **format, t_flagi *flag,va_list *arg);
/*
with and presision
*/
void				vivod_opchii(char **string, t_flagi *flag, va_list *arg);
void				get_flag(char **string, t_flagi *flag, va_list *arg);
void				vivod_flagi(char **string, t_flagi *flag, va_list *arg);
void				vivod_width(char **string, t_flagi *flag, va_list *arg)
{
/*
дополнительные функции
*/
void				sbros_flagov(t_flagi *flag);



#endif
