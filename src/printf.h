/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 05:08:39 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/30 21:17:46 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libtft/libft.h"

typedef struct s_formats
{
	int	plus;
	int	minus;
	int	hash;
	int	zero;
	int	space;
	int	with;
	int	with_dot;

}				t_formats;

int			ft_printf(char *a, ...);
int			ft_ncounter(int *b, va_list arg, char *s);
void		parsing(t_formats *strackt, int *b, char *s);

int			get_flags(t_formats *strackt, int i, char *s);
int			width (t_formats *strackt, int b, char *s);
int 		precision (t_formats *strackt, int b, char *s);

#endif
