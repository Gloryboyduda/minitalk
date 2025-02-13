/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:58 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 18:06:57 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "client.h"
int	main()
{
	int pid = getpid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putnbr_fd(pid, 1);
	fputstr("\n", 1);
	while (1)
	{
		pause();
	}
}