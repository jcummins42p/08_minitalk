/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:38:43 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/31 18:19:06 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*int	main(void)*/
/*{*/
	/*unsigned char	c;*/

	/*c = 213;*/
	/*if (ft_isprint(c))*/
		/*printf("Character is printable");*/
	/*else if (!ft_isprint(c))*/
		/*printf("Character is not printable");*/
	/*return (0);*/
/*}*/
