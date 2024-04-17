/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:24:18 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 17:22:34 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = (unsigned char)c;
	return (s);
}

/*int	main(void)*/
/*{*/
	/*char msg[] = "test with this array of characters";*/

	/*printf("The string before memset is %s\n", msg);*/
	/*memset(msg, '0', 5);*/
	/*printf("The string after memset is %s\n", msg);*/
	/*return (0);*/
/*}*/
