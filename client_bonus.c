/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:15:07 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 17:12:54 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

static void	send_signal(pid_t pid, unsigned char char_message)
{
	int		i;
	char	bit_tmp;

	i = 8;
	while (i > 0)
	{
		i--;
		bit_tmp = char_message >> i;
		if (bit_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(420);
	}
}

static void	handle_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Received message\n");
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;
	int		i;

	signal(SIGUSR2, handle_signal);
	if (argc != 3)
	{
		ft_printf("Error! Sould be : %s <sever_pid> <your_message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, SIGUSR2) == -1)
	{
		ft_printf("Error! Server pid not correct");
		exit(0);
	}
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(pid, message[i++]);
	send_signal(pid, '\0');
	return (0);
}
