/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/18 16:10:46 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int	decode_char(const int *octet, char *buffer, int *buf_index)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < 8)
		c = (c << 1) | octet[i++];
	if (c == '\0')
	{
		write(1, buffer, *buf_index);
		write(1, "\n", 1);
		*buf_index = 0;
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
	}
	return (1);
}

void	handler_usr(int sig_num)
{
	static char	buffer[HBUFF_SIZE];
	static int	buffer_index = 0;
	static int	octet[8];
	static int	i = 0;

	signal(sig_num, handler_usr);
	if (sig_num == SIGUSR1)
		octet[i++] = 0;
	else if (sig_num == SIGUSR2)
		octet[i++] = 1;
	if (i == 8)
	{
		decode_char(octet, buffer, &buffer_index);
		while (i > 0)
			octet[--i] = -1;
	}
	/*fflush(stdout);*/
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	signal(SIGUSR1, handler_usr);
	signal(SIGUSR2, handler_usr);
	ft_printf("Server pid:	%d\n", server_pid);
	while (1)
		pause();
	return (0);
}
