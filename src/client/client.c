/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/08/22 18:01:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	g_bytes_sent = 0;

void	receive_continue(int sig_num, siginfo_t *info, void *context)
{
	static size_t	bytes_confirmed = 0;

	(void)info;
	(void)context;
	if (sig_num == SIGUSR2)
	{
		bytes_confirmed++;
		if (bytes_confirmed == g_bytes_sent)
		{
			ft_printf("Message sent succesfully\n");
		}
	}
}

void	send_null(int *status, const int server_pid)
{
	size_t	i;

	i = -1;

	while (++i < 8)
	{
		if (*status < 0)
			return ;
		*status = kill(server_pid, SIGUSR1);
		pause();
	}
}

void	send_char(int *status, const int server_pid, const char c)
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
			*status = (kill(server_pid, SIGUSR1));
		else if (octet[7 - i] == '1')
			*status = (kill(server_pid, SIGUSR2));
		pause();
		if (*status < 0)
			return ;
	}
}

void	send_string(const int server_pid, const char *str)
{
	int		status;
	size_t	i;

	status = -1;
	g_bytes_sent = ft_strlen(str);
	i = 0;
	while (i < g_bytes_sent)
		send_char(&status, server_pid, str[i++]);
	send_null(&status, server_pid);
	if (status < 0)
	{
		ft_printf("Pid %d not a valid server\n", server_pid);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	mt_client;

	mt_client.sa_sigaction = receive_continue;
	mt_client.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &mt_client, NULL);
	sigaction (SIGUSR2, &mt_client, NULL);
	if (argc < 3)
		ft_printf("Please provide a valid server pid and string to send\n");
	else if (argc == 3)
		send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
