/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:32:47 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 16:58:42 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_isalpha(int c)*/
/*{*/
	/*if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))*/
		/*return (1);*/
	/*else*/
		/*return (0);*/
/*}*/

/*int	ft_isdigit(int c)*/
/*{*/
	/*if (c >= '0' && c <= '9')*/
		/*return (1);*/
	/*else*/
		/*return (0);*/
/*}*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*int	main(void)*/
/*{*/
	/*unsigned char	c;*/

	/*c = '(';*/
	/*if (ft_isalnum(c))*/
		/*printf("The supplied char is alphanumeric");*/
	/*else*/
		/*printf("The supplied char is not alphanumeric");*/
	/*return (0);*/
/*}*/
