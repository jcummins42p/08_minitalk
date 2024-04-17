/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/17 19:26:08 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(int server_pid)
{
	size_t	i;

	i = -1;
	while (++i < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(100);
	}
}

void	send_string(int server_pid, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
				kill(server_pid, SIGUSR1);
			else if (str[i][j] == '1')
				kill(server_pid, SIGUSR2);
			else
			{
				ft_printf("Error, non binary input\n");
				break ;
			}
			usleep(100);
			j++;
		}
		i++;
	}
	send_null(server_pid);
}

char	*encode_char(char c)
{
	char	*out;
	int		val;
	size_t	i;

	out = malloc(sizeof (char *) * 9);
	if (!out)
		return (NULL);
	val = (int)c;
	i = 0;
	while (i < 8)
	{
		if (val % 2)
			out[7 - i++] = '1';
		else
			out[7 - i++] = '0';
		val >>= 1;
	}
	out[8] = '\0';
	return (out);
}

char	**encode_string(char *str)
{
	char	**bin;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	bin = malloc((len + 1) * sizeof(char *));
	if (!bin)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bin[i] = encode_char(str[i]);
		i++;
	}
	bin[len] = NULL;
	return (bin);
}

int	main(int argc, char *argv[])
{
	char	**bin;

	if (argc < 3)
	{
		ft_printf("Please provide a valid server pid and string to send\n");
	}
	else if (argc == 3)
	{
		bin = encode_string(argv[2]);
		send_string(ft_atoi(argv[1]), bin);
	}
	return (0);
}
