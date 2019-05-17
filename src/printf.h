/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 05:08:39 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/16 19:51:27 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_formats
{
	int	plus;
	int	minus;
	int	hash;
	int	zero;
	int	space;
}				t_formats;

void    ft_putchar(char c);
void    ft_putstr(char *str);
size_t  ft_abs(long long ab);
size_t	ft_strlen(char *str);
char    *itoa_napolnotel(char *tabula, long long znachenie, int baza, int flagi);
char    *ft_atoi_baze(long long znachenie, int baze);
int		ft_counter1 (int i, va_list arg, const char *s);
int		ft_counter2(int i, va_list arg, const char *s);
int		ft_ncounter3(int i, const char *s);
int		ft_ncounter(int i, va_list arg, const char *s);
int		ft_printf(const char *restrict a, ...);

#endif
