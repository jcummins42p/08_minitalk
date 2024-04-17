/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:54:17 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/31 18:51:57 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (*s)
	{
		if (*s == (char)c)
			found = 1;
		s++;
		i++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (!found)
		return (NULL);
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}

/*int	main(void)*/
/*{*/
	/*const char		*str;*/
	/*unsigned char	c;*/

	/*str = "The quick brown fox jumps over the lazy dog";*/
	/*c = 'T';*/
	/*printf("found %c at \"%s\"\n", c, ft_strrchr(str, c));*/
	/*return (0);*/
/*}*/
