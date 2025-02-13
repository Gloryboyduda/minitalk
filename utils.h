/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:18:22 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/13 20:26:27 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

char		*ft_strjoin_n(char *s1, char *s2, size_t n);
void		fputstr(char *str, int fd);
void		send_char(char c, int pid);
void		signal_handler(int sig);
size_t		ft_strlen(char *str);
void		ft_putnbr_fd(int n, int fd);

#endif