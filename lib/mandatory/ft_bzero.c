/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:55:00 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/25 18:39:56 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main(void)*/
/*{*/
	/*char	teststr[11] = "test string";*/

	/*printf("%s\n", teststr);*/
	/*ft_bzero(teststr, 5);*/
	/*printf("%s\n", teststr + 5);*/
	/*return (0);*/
/*}*/
