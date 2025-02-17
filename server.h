/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:08 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/17 12:32:55 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "utils.h"

typedef struct s_server
{
	char	c;
	int		received_bits;
	char	*msg;
}	t_server;

t_server	*global_server(void);
void		signal_handler(int sig, siginfo_t *info, void *context);

#endif