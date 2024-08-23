/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:05:07 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/21 16:54:35 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(char *c);
void	ft_putchar_nb(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
int		ft_printf_hex(unsigned int x, char c);
int		ft_printf_char(int c);
int		ft_printf_int(int i);
int		ft_printf_uint(unsigned int i);
int		ft_printf_ptr(unsigned long long p);
int		ft_printf_str(char *s);
int		ft_check_flag(const char s1, const char s2, va_list args, int count);

int		ft_atoi(const char *str);

#endif