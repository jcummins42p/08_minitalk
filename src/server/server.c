/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/18 16:49:57 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm()
{
	/*(void)pid;*/
	ft_printf("Signal sent successfully");
}

void	error()
{
	/*(void)pid;*/
	ft_printf("Signal not sent successfully");
}

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
		return(1);
	}
	else
	{
		buffer[*buf_index] = c;
		(*buf_index)++;
		if (*buf_index >= HBUFF_SIZE)
		{
			write(1, buffer, HBUFF_SIZE -1);
			*buf_index = 0;
			return (1);
		}
	}
	return (0);
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
		if (decode_binary(octet, buffer, &buffer_index))
			confirm();
		while (i > 0)
			octet[--i] = -1;
	}
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
