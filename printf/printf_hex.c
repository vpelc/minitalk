/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:06:01 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/28 15:57:22 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int x)
{
	int	count;

	count = 0;
	if (x == 0)
		count++;
	while (x > 0)
	{
		count++;
		x /= 16;
	}
	return (count);
}

int	ft_printf_hex(unsigned int x, char c)
{
	if (x >= 16)
	{
		ft_printf_hex(x / 16, c);
		ft_printf_hex(x % 16, c);
	}
	else
	{
		if (x <= 9)
			ft_putchar_nb((x + '0'));
		else
		{
			if (c == 'x')
				ft_putchar_nb((x - 10 + 'a'));
			if (c == 'X')
				ft_putchar_nb((x - 10 + 'A'));
		}
	}
	return (count_hex(x));
}

static void	convert_hex(unsigned long long p)
{
	char	*base;

	base = "0123456789abcdef";
	if (p >= 16)
	{
		convert_hex(p / 16);
	}
	ft_putchar_nb(base[p % 16]);
}

int	ft_printf_ptr(unsigned long long p)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	count += 2;
	convert_hex(p);
	if (p == 0)
		count++;
	while (p > 0)
	{
		count++;
		p /= 16;
	}
	return (count);
}
