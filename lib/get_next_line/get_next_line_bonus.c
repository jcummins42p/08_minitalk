/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:02:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/16 20:25:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*split_newline(char *str)
{
	char	*rem;
	size_t	i;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	rem = ft_strdup(str);
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i])
		str[++i] = '\0';
	ft_memmove(rem, rem + i, len - i);
	rem[len - i] = '\0';
	return (rem);
}

char	*get_buffer(int fd)
{
	char	*buf;
	int		bytes_read;

	if (fd < 0 || fd > 999)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free (buf);
		return (NULL);
	}
	buf[bytes_read] = '\0';
	return (buf);
}

int	extend_line(int fd, char **line)
{
	char	*swap;
	char	*out;
	int		success;

	swap = NULL;
	out = NULL;
	success = 0;
	swap = get_buffer(fd);
	if (swap)
	{
		success = 1;
		out = ft_strjoin(*line, swap);
	}
	else
		out = ft_strdup(*line);
	free (swap);
	free (*line);
	*line = ft_strdup(out);
	free (out);
	return (success);
}

char	*get_line(int fd)
{
	static char		remainder[1024][(BUFFER_SIZE) + 1];
	char			*line;
	char			*swap;

	line = NULL;
	swap = NULL;
	if (remainder[fd][0] == 0)
	{
		line = get_buffer(fd);
		if (!line || *line == '\0')
		{
			free (line);
			return (NULL);
		}
	}
	else if (remainder[fd][0])
		line = ft_strdup(remainder[fd]);
	while (!is_complete(line) && extend_line(fd, &line))
		;
	swap = split_newline(line);
	if (swap)
		ft_memmove(remainder[fd], swap, ft_strlen(swap));
	remainder[fd][ft_strlen(swap)] = '\0';
	free (swap);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd);
	if (!line || *line == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

void	print_file(int fd)
{
	char	*buf;

	buf = get_next_line(fd);
	if (buf)
	{
		printf("%s", buf);
		free (buf);
	}
	else
		return ;
}

/*int	main(int argc, char *argv[])*/
/*{*/
	/*int		fd;*/
	/*int		i;*/

	/*if (argc == 1)*/
	/*{*/
		/*printf("No file specified\n");*/
		/*return (0);*/
	/*}*/
	/*i = 1;*/
	/*while (argv[i])*/
	/*{*/
		/*fd = open(argv[i], O_RDONLY);*/
		/*print_file(fd);*/
		/*close (fd);*/
		/*i++;*/
	/*}*/
	/*return (0);*/
/*}*/
