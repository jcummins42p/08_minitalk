/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:28:36 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/25 18:45:50 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = dest;
	psrc = src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}

/*int	main(void)*/
/*{*/
	/*char	src[11] = "Hello There";*/
	/*char	dest[14] = "General Kenobi";*/

	/*src = "Hello There";*/
	/*dest = "General Kenobi";*/
	/*printf("%s, %s!\n", src, dest);*/
	/*ft_memcpy(dest, src, 10);*/
	/*printf("%s, %s!\n", src, dest);*/
	/*return (0);*/
/*}*/
