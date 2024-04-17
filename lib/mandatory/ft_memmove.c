/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:28:36 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/31 18:16:07 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (src > dest)
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (n > 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
	}
	return (dest);
}

/*int	main(void)*/
/*{*/
	/*char	src[] = "Hello There";*/
	/*char	dest[] = "General Kenobi";*/

	/*printf("%s!\n", dest);*/
	/*printf("%s!\n", src);*/
	/*ft_memmove(src + 6, src, 5);*/
	/*printf("%s!\n", src);*/
	/*return (0);*/
/*}*/
