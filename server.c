/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:58 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/17 12:32:38 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

t_server	*global_server(void)
{
	static t_server	server;

	return (&server);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
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
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	global_server()->msg = ft_strdup("");
	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	fputstr("Server Pid: ", 1);
	ft_putnbr_fd(pid, 1);
	fputstr("\n", 1);
	while (1)
	{
		pause();
	}
}
