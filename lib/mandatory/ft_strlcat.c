/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:48:46 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/15 20:42:52 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	dlen = i;
	while (src[i - dlen] && i < size - 1)
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (dlen < size)
		dst[i] = '\0';
	return (dlen + ft_strlen(src));
}

/*int	main(void)*/
/*{*/
	/*char dst[30];*/
	/*char *src = (char *)"AAAAAAAAA";*/
	/*ft_memset(dst, 0, 30);*/
	/*dst[0] = 'B';*/

	/*ft_memset(dst, 'B', 4);*/
	/*printf("Return Value is %d\n", (int)ft_strlcat(dst, src, 3));*/
	/*printf("%s\n", dst);*/
/*// 4*/
	/*printf("Return Value is %d\n", (int)ft_strlcat(dst, src, 6));*/
	/*printf("%s\n", dst);*/
/*//5*/
	/*ft_memset(dst, 'C', 5);*/
	/*printf("Return Value is %d\n", (int)ft_strlcat(dst, src, -1));*/
	/*printf("%s\n", dst);*/
/*//6*/
	/*return(0);*/
/*}*/
