/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:14:23 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:47 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int	main(void)*/
/*{*/
	/*unsigned char	c;*/

	/*c = '5';*/
	/*{*/
		/*if (ft_isdigit(c))*/
			/*printf("The char %c is a digit", c);*/
		/*else*/
			/*printf("The char %c is not a digit", c);*/
	/*}*/
	/*return (0);*/
/*}*/
