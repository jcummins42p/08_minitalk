/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/18 22:22:16 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	decode_binary(const int *octet, char *buffer, int *buf_index)
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
		*buf_index = 0;
		return (1);
	}
	else
	{
		buffer[*buf_index] = c;
		(*buf_index)++;
		if (*buf_index >= HBUFF_SIZE)
		{
			write(1, buffer, HBUFF_SIZE -1);
			*buf_index = 0;
		}
		return (0);
	}
}

void	receive_string(int sig_num, siginfo_t *info, void *context)
{
	static char	buffer[HBUFF_SIZE];
	static int	buffer_index = 0;
	static int	octet[8];
	static int	i = 0;

	(void)context;
	if (sig_num == SIGUSR1 || sig_num == SIGUSR2)
	{
		kill(info->si_pid, SIGUSR1);
		if (sig_num == SIGUSR1)
			octet[i++] = 0;
		else if (sig_num == SIGUSR2)
			octet[i++] = 1;
	}
	if (i == 8)
	{
		kill(info->si_pid, SIGUSR2);
		decode_binary(octet, buffer, &buffer_index);
		while (i > 0)
			octet[--i] = 0;
	}
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	new_action;

	server_pid = getpid();
	new_action.sa_sigaction = receive_string;
	sigemptyset (&new_action.sa_mask);
	new_action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &new_action, NULL);
	sigaction (SIGUSR2, &new_action, NULL);
	ft_printf("Server pid:	%d\n", server_pid);
	while (1)
		pause();
	return (0);
}
