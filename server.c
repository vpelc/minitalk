/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:25:52 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 14:21:02 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

char	*ft_calloc(void)
{
	char	*calloc;

	calloc = malloc(sizeof(char) * 1);
	if (!calloc)
		return (0);
	calloc[0] = '\0';
	return (calloc);
}

char	*ft_strjoin(char *str1, char str2)
{
	char	*join;
	size_t	i;

	i = 0;
	if (!str1)
		return (NULL);
	join = malloc((ft_strlen(str1) + 2));
	if (!join)
		return (free(str1), NULL);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	join[i] = str2;
	join[i + 1] = '\0';
	return (join);
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int				bit_shift;
	static unsigned char	c;
	static char				*str;

	(void)context;
	(void)info;
	if (!str)
		str = ft_calloc();
	c |= (signal == SIGUSR1);
	bit_shift++;
	if (bit_shift == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_strjoin(str, c);
		bit_shift = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &handle_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
