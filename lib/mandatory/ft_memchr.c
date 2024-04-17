/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:17:08 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/25 18:50:36 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temps;

	temps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temps[i] == (unsigned char)c)
			return ((char *)(&temps[i]));
		i++;
	}
	return (NULL);
}

/*int	main(void)*/
/*{*/
	/*const char		*str;*/
	/*unsigned char	c;*/
	/*size_t			n;*/

	/*str = "The quick :@ brown fox :P jumps over :0 the lazy :| dog!";*/
	/*c = 'z';*/
	/*n = 60;*/
	/*printf("Found %c at \"%s\" in string.\n", c, ft_memchr(str, c, n));*/
/*}*/
