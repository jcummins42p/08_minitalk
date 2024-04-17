/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/17 19:26:45 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_bin_buff[9];

void	handler_one(int sig_num)
{
	signal(sig_num, handler_one);
	write(1, "0", 1);
	fflush(stdout);
}

void	handler_two(int sig_num)
{
	signal(sig_num, handler_two);
	write(1, "1", 1);
	fflush(stdout);
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	signal(SIGUSR1, handler_one);
	signal(SIGUSR2, handler_two);
	ft_printf("Server pid:	%d\n", server_pid);
	while(1)
	{
		pause();
	}
	return (0);
}
