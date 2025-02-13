/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:58 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 16:56:27 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server	*global_server()
{
	t_server	server;
	return &server;
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("Received SIGUSR1\n", 1);
	if (sig == SIGUSR2)
		ft_putstr_fd("Received SIGUSR2\n", 1);
}

int	main()
{
	
}