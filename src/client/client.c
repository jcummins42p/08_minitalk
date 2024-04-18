/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/18 16:13:22 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(const int server_pid)
{
	size_t	i;

	i = -1;
	while (++i < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(500);
	}
}

void	send_char(const int server_pid, const char c)
{
	char	octet[8];
	int		val;
	int		i;

	val = (int)c;
	i = -1;
	while (i++ < 7)
	{
		if (val % 2)
			octet[7 - i] = '1';
		else
			octet[7 - i] = '0';
		val >>= 1;
	}
	while (i-- > 0)
	{
		if (octet[7 - i] == '0')
			kill(server_pid, SIGUSR1);
		else if (octet[7 - i] == '1')
			kill(server_pid, SIGUSR2);
		usleep(500);
	}
}

void	send_string(const int server_pid, const char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
		send_char(server_pid, str[i++]);
	send_null(server_pid);
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
	{
		ft_printf("Please provide a valid server pid and string to send\n");
	}
	else if (argc == 3)
	{
		send_string(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
