/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:36:42 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/28 15:25:46 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hashtag_flag(char s2, va_list args, int count)
{
	if ((s2 == 'x' || s2 == 'X') && va_arg(args, unsigned int) == 0)
	{
		count += 1;
		return (count);
	}
	else if (s2 == 'x')
	{
		count += ft_printf_str("0x");
		return (count);
	}
	else if (s2 == 'X')
	{
		count += ft_printf_str("0X");
		return (count);
	}
	return (0);
}

static int	ft_space_flag(char s2, va_list args, int count)
{
	if (s2 == 'd' || s2 == 'i')
	{
		if (va_arg(args, int) >= 0)
		{
			count += ft_printf_char(' ');
			return (count);
		}
		else
		{
			count += 1;
			return (count);
		}
	}
	else if (s2 == 's')
	{
		count += 1;
		return (count);
	}
	return (0);
}

static int	ft_plus_flag(char s2, va_list args, int count)
{
	int		a;

	a = va_arg(args, int);
	if ((s2 == 'd' || s2 == 'i') && a >= 0)
	{
		count += ft_printf_char('+');
		return (count);
	}
	else if ((s2 == 'd' || s2 == 'i') && a < 0)
	{
		count += 1;
		return (count);
	}
	return (0);
}

int	ft_check_flag(const char s1, const char s2, va_list args, int count)
{
	va_list	argscopy;

	va_copy(argscopy, args);
	if (s1 == '#')
		count = ft_hashtag_flag(s2, argscopy, count);
	else if (s1 == ' ')
		count = ft_space_flag(s2, argscopy, count);
	else if (s1 == '+')
		count = ft_plus_flag(s2, argscopy, count);
	return (va_end(argscopy), count);
}
