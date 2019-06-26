/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtftprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:58:41 by ieropaie          #+#    #+#             */
/*   Updated: 2019/06/26 03:21:08 by ieropaie         ###   ########.fr       */
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
int					melkay_s(va_list *arg, t_flagi *flag);
int					bolshoy_s(va_list *arg, t_flagi *flag);
/*
with and presision
*/
void				vivod_opchii(char **string, t_flagi *flag, va_list *arg);
void				vivod_flagi(char **string, t_flagi *flag, va_list *arg);
void				vivod_width(char **string, t_flagi *flag, va_list *arg);
void				vivod_precision(char **string, t_flagi *flag, va_list *arg);
void				vivod_length(char **string, t_flagi *flag, va_list *arg);
intmax_t			poluchit_tip(va_list *arg, t_flagi *flag);
uintmax_t			poluchit_unsign_tip(va_list *arg, t_flagi *flag);


/*
дополнительные функции
*/
void				sbros_flagov(t_flagi *flag);
void				probel(int width, int len);
void				zeroo(int width, int len);
void				leviy_probel_shag(t_flagi *flag, int dlinna);
int					wchar_dlinna(wchar_t c);
int					wstr_ndlinna(wchar_t *s, int n);
int					wstr_dlinna(wchar_t *s);
int					wstr_ndlinna(wchar_t *s, int n);
int					wstr_dlinna(wchar_t *s);



#endif
