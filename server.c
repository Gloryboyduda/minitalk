/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:58 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/14 11:26:24 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server	*global_server(void)
{
	static t_server	server;

	return (&server);
}

void	signal_handler(int sig)
{
	global_server()->c <<= 1;
	if (sig == SIGUSR2)
		global_server()->c |= 1;
	global_server()->received_bits++;
	if (global_server()->received_bits == 8)
	{
		global_server()->received_bits = 0;
		global_server()->msg = ft_strjoin_n(global_server()->msg,
		&global_server()->c, 1);
		if (global_server()->c == '\0')
			{
				fputstr(global_server()->msg, 1);
				fputstr("\n", 1);
				free(global_server()->msg);
				global_server()->msg = NULL;
			}
			global_server()->c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	fputstr("Server Pid: ", 1);
	ft_putnbr_fd(pid, 1);
	fputstr("\n", 1);
	while (1)
	{
		pause();
	}
}
