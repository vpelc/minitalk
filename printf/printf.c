/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:24:19 by vpelc             #+#    #+#             */
/*   Updated: 2024/06/04 16:59:27 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_exception(va_list args, char c1, char c2)
{
	va_list	argscopy;
	int		a;

	va_copy(argscopy, args);
	a = va_arg(argscopy, int);
	if (c1 == ' ' && c2 == 's')
		return (va_end(argscopy), 1);
	else if (c1 == '#' && (c2 == 'x' || c2 == 'X') && a == 0)
		return (va_end(argscopy), 1);
	else if (a < 0 && (c1 == ' ' || c1 == '+') && (c2 == 'd' || c2 == 'i'))
		return (va_end(argscopy), 1);
	return (va_end(argscopy), 0);
}

static int	ft_print_arg(va_list args, const char s, int count)
{
	if (s == 'c')
		count += ft_printf_char(va_arg(args, int));
	else if (s == 's')
		count += ft_printf_str(va_arg(args, char *));
	else if (s == 'p')
		count += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (s == 'd' || s == 'i')
		count += ft_printf_int(va_arg(args, int));
	else if (s == 'u')
		count += ft_printf_uint(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		count += ft_printf_hex(va_arg(args, unsigned int), s);
	else if (s == '%')
		count += ft_printf_char(s);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;
	int		tmp;

	count = 0;
	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%#+ ", str[i + 1]))
		{
			tmp = count;
			count = ft_check_flag(str[i + 1], str[i + 2], args, count);
			if (count != tmp)
				i++;
			if (ft_check_exception(args, str[i], str[i + 1]))
				count--;
			count = ft_print_arg(args, str[i + 1], count);
			i++;
		}
		else if (str[i] != '%')
			count += ft_printf_char(str[i]);
	}
	return (va_end(args), count);
}

/*  #include <stdio.h>
#include <limits.h>

# define ARG "%u\n", 4294967295u

int	main(void)
{
	int r1 = ft_printf(ARG);
	int r2 = printf(ARG);

	printf("\nmine = %d, origin = %d\n", r1, r2);
	return (0);
}  */