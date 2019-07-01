/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtftprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:58:41 by ieropaie          #+#    #+#             */
/*   Updated: 2019/07/01 05:12:48 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTFTPRINTF_H
# define LIBTFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct		s_flagi
{
	int				pres;
	int				prec;
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
	int				width;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_length;
}					t_flagi;

int					ft_printf(const char *format, ...);
int					parsser(char **format, t_flagi *flag, va_list *arg);
int					spechificator(char **format, t_flagi *flag, va_list *arg);
int					melkay_s(va_list *arg, t_flagi *flag);
int					melkay_c(va_list *arg, t_flagi *flag);
int					melkay_d(va_list *arg, t_flagi *flag);
int					melkay_i(va_list *arg, t_flagi *flag);
int					melkay_o(va_list *arg, t_flagi *flag);
int					melkay_p(va_list *arg, t_flagi *flag);
int					melkay_u(va_list *arg, t_flagi *flag);
int					melkay_x(va_list *arg, t_flagi *flag);
int					modul(va_list *arg, t_flagi *flag);
int					bolshoy_d(va_list *arg, t_flagi *flag);
int					bolshoy_s(va_list *arg, t_flagi *flag);
int					bolshoy_c(va_list *arg, t_flagi *flag);
int					bolshoy_o(va_list *arg, t_flagi *flag);
int					bolshoy_u(va_list *arg, t_flagi *flag);
int					bolshoy_x(va_list *arg, t_flagi *flag);
void				vivod_opchii(char **string, t_flagi *flag, va_list *arg);
void				vivod_flagi(char **string, t_flagi *flag, va_list *arg);
void				vivod_width(char **string, t_flagi *flag, va_list *arg);
void				vivod_precision(char **string, t_flagi *flag, va_list *arg);
void				vivod_length(char **string, t_flagi *flag, va_list *arg);
int					wide_char_dlinna(wchar_t c);
int					wide_str_ndlinna(wchar_t *s, int n);
int					wsd01(wchar_t *s);
int					wstr_dln(wchar_t *s, int n);
void				poluchit_int(intmax_t nb);
int					poluchit_flagi_dlina(intmax_t nb, t_flagi *flag);
int					poluchit_dlinna(intmax_t nb);
void				stavim_int_leviy_probel(t_flagi *flag,
					int dlinna, intmax_t nb);
void				probel(int width, int dlinna);
void				zeroo(int width, int dlinna);
void				leviy_probel_shag(t_flagi *flag, int dlinna);
int					undefined(char c, t_flagi *flag);
intmax_t			poluchit_tip(va_list *arg, t_flagi *flag);
uintmax_t			poluchit_unsign_tip(va_list *arg, t_flagi *flag);
void				un_int_poluchit(uintmax_t nb, char *string, int base);
int					un_int_poluchit_dlin(uintmax_t nb,
					int base);
int					un_int_poluchit_flag_dlinna(uintmax_t nb,
					t_flagi *flag, int base);
void				pst_uint_lspace(t_flagi *flag,
					int dlinna, uintmax_t nb, int type);

#endif
