/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:45:54 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 17:36:27 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}

/*int	main(int argc, char **argv)*/
/*{*/
	/*if (argc != 2)*/
	/*{*/
		/*write(1, "Error, please provide one argument\n", 34);*/
		/*return (1);*/
	/*}*/
	/*else*/
	/*{*/
		/*printf("The string in uppercase is %s\n", ft_toupper(argv[1]));*/
	/*}*/
	/*return (0);*/
/*}*/
