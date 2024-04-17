/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:44:23 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:40 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		c += 32;
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
		/*printf("The string in lowercase is %s\n", ft_tolower(argv[1]));*/
	/*}*/
	/*return (0);*/
/*}*/
