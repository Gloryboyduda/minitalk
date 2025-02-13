/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:16:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 20:36:07 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "server.h"

size_t  ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
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
