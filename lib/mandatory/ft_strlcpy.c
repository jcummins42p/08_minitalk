/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:58:48 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/31 19:12:44 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)*/
/*{*/
	/*char			dest[7] = "ABCDEF\0";*/
	/*char			src[7] = "HIJKLM";*/
	/*unsigned int	size;*/
	/*unsigned int	retval;*/

	/*retval = 0;*/
	/*size = 5;*/
	/*printf("The original string is %s\n", dest);*/
	/*retval = ft_strlcpy(dest, src, size);*/
	/*printf("The copied string is %s of length %d\n", dest, retval);*/
	/*return (0);*/
/*}*/
