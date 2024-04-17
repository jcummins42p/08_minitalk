/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:29:36 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)*/
/*{*/
	/*int	c;*/

	/*c = 'C';*/
	/*if (ft_isascii(c))*/
		/*printf("Character is ASCII");*/
	/*else if (ft_isascii(c))*/
		/*printf("Character is not ASCII");*/
	/*return (0);*/
/*}*/
