/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:57:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 18:28:26 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_message(char *str, int pid)
{
	int i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}


int main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		fputstr("Invalid number of arguments\n", 1);
		return (1);
	}
	pid = atoi(av[1]);
	send_message(av[2], pid);
}
