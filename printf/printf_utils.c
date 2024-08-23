/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:39:24 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/03 16:28:51 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c && c[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar_nb(s[i]);
		i++;
	}
}

void	ft_putchar_nb(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_nb('-');
	}
	if (l >= 10)
	{
		ft_putnbr(l / 10);
		ft_putchar_nb(l % 10 + 48);
	}
	if (l < 10)
		ft_putchar_nb(l % 10 + 48);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	str = (char *)s;
	n = ft_strlen(str);
	while (i < n && str[i] != (unsigned char)c)
		i++;
	if (i >= n)
		return (0);
	return (1);
}
