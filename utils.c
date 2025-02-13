/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:16:40 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 18:36:15 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "server.h"
#include <signal.h>

void	fputstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
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
		usleep(100);
	}
}

t_server	*global_server()
{
	static t_server	server;
	return (&server);
}

void	signal_handler(int sig)
{
	
	global_server()->c  <<= 1;
	if (sig == SIGUSR2)
		global_server()->c  |= 1;
	global_server()->received_bits++;
	if (global_server()->received_bits == 8)
	{
		global_server()->received_bits = 0;
		write(1, &global_server()->c, 1);
		global_server()->c = 0;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	number;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n %= 10, fd);
		}
		else
		{
			number = n + '0';
			write(fd, &number, 1);
		}
	}
}
