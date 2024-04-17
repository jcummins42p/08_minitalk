/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:05:20 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/16 15:36:14 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] == set[0])
		i++;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	trim = ft_substr(s1, 0, i + 1);
	return (trim);
}

/*int	main(void)*/
/*{*/
	/*char	*s = "GGGHello There!GGGGG";*/
	/*char	c = 'G';*/

	/*printf("The trimmed string is: \"%s\"\n", ft_strtrim(s, c));*/
	/*return (0);*/
/*}*/
