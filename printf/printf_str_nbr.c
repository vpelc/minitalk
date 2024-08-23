/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:28:49 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/03 19:02:55 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	int	count;

	count = 0;
	ft_putchar_nb(c);
	count++;
	return (count);
}

int	ft_printf_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	count += ft_strlen(s);
	return (count);
}

int	ft_printf_int(int i)
{
	int	j;
	int	count;

	count = 0;
	j = i;
	ft_putnbr(i);
	if (i == 0)
	{
		count++;
		return (count);
	}
	if (j < 0)
		count++;
	while (j != 0)
	{
		count++;
		j /= 10;
	}
	return (count);
}

static void	ft_put_unbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_put_unbr(n / 10);
		ft_putchar_nb(n % 10 + 48);
	}
	if (n < 10)
		ft_putchar_nb(n % 10 + 48);
}

int	ft_printf_uint(unsigned int i)
{
	int	count;

	count = 0;
	ft_put_unbr(i);
	if (i == 0)
	{
		count++;
		return (count);
	}
	while (i != 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}
