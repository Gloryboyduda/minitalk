/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:16:40 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 20:36:29 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin_n(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s2)
		return (free(s1), NULL);
	new = malloc(ft_strlen(s1) + n + 1);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (i < n)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (free(s1), new);
}

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
