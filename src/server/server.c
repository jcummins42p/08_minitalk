/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/18 15:16:30 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		decode_char(const int *octet)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c *= 2;
		c += octet[i++];
	}
	if (c == '\0')
		write(1, "\n", 1);
	else
		write(1, &c, 1);
	fflush(stdout);
	return (1);
}

void	handler_usr(int sig_num)
{
	static int	octet[8];
	static int	i = 0;

	signal(sig_num, handler_usr);
	if (sig_num == SIGUSR1)
		octet[i++] = 0;
	else if (sig_num == SIGUSR2)
		octet[i++] = 1;
	if (i == 8)
	{
		decode_char(octet);
		while (i > 0)
			octet[--i] = -1;
	}
	fflush(stdout);
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
