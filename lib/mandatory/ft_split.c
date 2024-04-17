/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:46:20 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/16 16:57:12 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	wcount(char const *s, char c)
{
	int	i;
	int	words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static unsigned int	lcount(char const *s, char c, int i)
{
	int	letters;

	letters = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		letters++;
		i++;
	}
	return (letters);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	word;

	i = 0;
	word = 0;
	split = (char **)malloc((wcount(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (word < wcount(s, c))
	{
		while (s[i] == c)
			i++;
		split[word] = ft_substr(s, i, lcount(s, c, i));
		i += lcount(s, c, i);
		word++;
	}
	split[word] = NULL;
	return (split);
}

/*int	main(void)*/
/*{*/
	/*char const	*str;*/
	/*char		c;*/
	/*int			i;*/

	/*str = "   tripouille ";*/
	/*c = ' ';*/
	/*i = 0;*/
	/*while (i < 5)*/
		/*printf("Count of %s\n", ft_split(str, c)[i++]);*/
	/*return (0);*/
/*}*/
