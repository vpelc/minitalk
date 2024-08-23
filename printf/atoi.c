/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:48:14 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/21 16:02:16 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static	int	ft_isnegative(char str)
{
	if (str == '+')
		return (1);
	if (str == '-')
		return (-1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;	
	int	n;

	n = 1;
	r = 0;
	i = ft_isspace(str);
	if (ft_isnegative(str[i]) != 0)
	{
		n *= ft_isnegative(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10;
		r = r + (str[i] - 48);
		i++;
	}
	return (r * n);
}
