/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/16 21:04:42 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	while(1)
	{
		ft_printf("Server pid:	%d", server_pid);
		pause();
	}
	return (0);
}
