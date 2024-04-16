/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/16 21:41:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

void	connect(int server_pid)
{
	ft_printf("Supplied pid: %d\n", server_pid);
	sleep(3);
	kill(server_pid, SIGSTOP);
	ft_printf("Server stopped successfully\n");
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("Please provide a valid server pid\n");
	}
	else if (argc == 2)
	{
		connect(ft_atoi(argv[1]));
	}
	return (0);
}
