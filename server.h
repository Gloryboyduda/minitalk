/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:08 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 20:26:12 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
#include "utils.h"

typedef struct s_server
{
	int		pid;
	char	c;
	int		received_bits;
	char	*msg;
}	t_server;

void	signal_handler(int sig);

#endif