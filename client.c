/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:57:10 by duandrad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/22 10:51:07 by duandrad         ###   ########.fr       */
=======
/*   Updated: 2025/02/22 10:49:30 by duandrad         ###   ########.fr       */
>>>>>>> 6d916f3 (Fix PID output formatting and remove obsolete tester script)
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

bool	*ack(void)
{
	static bool	acknowlegde;

	return (&acknowlegde);
}

void	ack_handle(int sig)
{
	(void)sig;
	*ack() = 1;
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
		while (!*ack())
			usleep(100);
		*ack() = 0;
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
	ft_putnbr_fd("pid = %d\n", pid);
	if (pid < 0)
	{
		fputstr("Invalid PID\n", 1);
		return (1);
	}
	signal(SIGUSR1, ack_handle);
	send_message(av[2], pid);
	fputstr("Message sent successfully!\n", 1);
}
