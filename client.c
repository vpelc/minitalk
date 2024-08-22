/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:44:18 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 13:39:47 by vpelc            ###   ########.fr       */
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
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error! Tip : %s <sever_pid> <your_message> \n", argv[0]);
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
