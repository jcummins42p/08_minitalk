/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:14:18 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/28 13:50:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)*/
/*{*/
	/*char	*str;*/

	/*str = "hello";*/
	/*printf("The length of your string is %d", ft_strlen(str));*/
	/*return (0);*/
/*}*/
