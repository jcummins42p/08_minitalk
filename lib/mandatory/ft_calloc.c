/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:34 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/15 21:12:59 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	total = (nmemb * size);
	if (total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

/*int	main(void)*/
/*{*/
	/*int		*ptr;*/
	/*int		i;*/

	/*i = 0;*/
	/*ptr = (int *)ft_calloc(-5, -5);*/
	/*if (ptr == NULL)*/
	/*{*/
		/*printf("Memory not allocated");*/
		/*return (0);*/
	/*}*/
	/*while (i < 10)*/
	/*{*/
		/*printf("%d ", ptr[i]);*/
		/*i++;*/
	/*}*/
	/*return (0);*/
/*}*/
