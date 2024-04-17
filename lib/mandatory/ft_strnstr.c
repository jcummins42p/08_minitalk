/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:52:24 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/28 13:49:50 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	si;
	size_t	fi;
	size_t	found;

	si = 0;
	found = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[si] && si < len)
	{
		fi = 0;
		while ((big[si] == little[fi]) && (big[si]) && (si < len))
		{
			if (fi == 0)
				found = si;
			if (!(little[++fi]) && (little[fi - 1] == big[si]))
				return ((char *)&big[found]);
			si++;
		}
		si -= (fi - 1);
	}
	return (NULL);
}

/*int	main(void)*/
/*{*/
	/*const char	*big = "The quick brown fox jumps over the lazy dog";*/
	/*const char	*little = "T";*/
	/*size_t		len;*/

	/*len = 60;*/
	/*printf("%s", ft_strnstr(big, little, len));*/
	/*return (0);*/
/*}*/
