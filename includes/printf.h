/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 05:08:39 by ieropaie          #+#    #+#             */
/*   Updated: 2019/05/07 15:27:30 by ieropaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void    ft_putchar(char c);
void    ft_putstr(char *str);
size_t  ft_abs(long long ab);
size_t	ft_strlen(char *str);
char    *itoa_napolnotel(char *tabula, long long znachenie, int baza, int flagi);
char    *ft_atoi_baze(long long znachenie, int baze)

#endif
