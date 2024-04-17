/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:55 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/16 17:24:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	remap(unsigned int i, char *c)*/
/*{*/
	/*if (c[0] != ' ')*/
		/*c[0] = c[0] + i;*/
/*}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*int	main(void)*/
/*{*/
	/*char	str1[12] = "Hello There!";*/

	/*printf("Untranslated string: %s\n", str1);*/
	/*ft_striteri(str1, remap);*/
	/*printf("Translated string: %s\n", str1);*/
	/*return (0);*/
/*}*/
