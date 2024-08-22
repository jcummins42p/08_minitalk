/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/08/22 18:08:53 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_static(char *buffer, int *buffer_index, int *octet, int *i)
{
	ft_memset(buffer, 0, HBUFF_SIZE);
	ft_memset(octet, 0, sizeof(int) * 8);
	*buffer_index = 0;
	*i = 0;
}

int	decode_binary(int *octet, char *buffer, int *buf_index)
{
	int				*ptr;
	unsigned char	c;

	ptr = (int *)octet;
	c = 0;
	while (ptr < octet + 8)
		c = (c << 1) | *(ptr++);
	if (c == '\0')
	{
		write(1, buffer, *buf_index);
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		buffer[(*buf_index)++] = c;
		if (*buf_index >= HBUFF_SIZE)
		{
			write(1, buffer, HBUFF_SIZE);
			return (0);
		}
		return (1);
	}
}

void	receive_string(int sig_num, siginfo_t *info, void *context)
{
	static char	buffer[HBUFF_SIZE];
	static int	buffer_index = 0;
	static int	octet[8];
	static int	i = 0;

	(void)context;
	usleep(100);
	if (sig_num == SIGUSR1 || sig_num == SIGUSR2)
	{
		if (sig_num == SIGUSR1)
			octet[i++] = 0;
		else if (sig_num == SIGUSR2)
			octet[i++] = 1;
	}
	if (i == 8)
	{
		if (!decode_binary(octet, buffer, &buffer_index))
			reset_static(buffer, &buffer_index, octet, &i);
		else
			i = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	mt_server;

	mt_server.sa_sigaction = receive_string;
	mt_server.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &mt_server, NULL);
	sigaction (SIGUSR2, &mt_server, NULL);
	server_pid = getpid();
	ft_printf("Server pid:	%d\n", server_pid);
	while (1)
	{
		pause();
	}
	return (0);
}
