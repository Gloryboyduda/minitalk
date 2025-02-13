/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:08 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:50 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_server
{
	int		pid;
	char	c;
	int		received_bits;
}	t_server;

void	signal_handler(int sig);
void	ft_putnbr_fd(int n, int fd);

#endif