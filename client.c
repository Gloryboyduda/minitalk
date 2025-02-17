/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:57:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/17 12:42:46 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

sig_atomic_t	g_ack_received = 0;

void	ack_handle(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(char c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		while (!g_ack_received)
			pause();
		g_ack_received = 0;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(0, pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		fputstr("Invalid number of arguments\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0)
	{
		fputstr("Invalid PID\n", 1);
		return (1);
	}
	signal(SIGUSR1, ack_handle);
	send_message(av[2], pid);
	fputstr("\n", 1);
}
