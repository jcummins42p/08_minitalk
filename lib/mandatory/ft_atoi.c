/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:03:56 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = (44 - nptr[i++]);
	while (nptr[i] && ((nptr[i] >= '0') && nptr[i] <= '9'))
		result = (result * 10) + (nptr[i++] - '0');
	return (result * sign);
}

/*int	main(void)*/
/*{*/
	/*const char	*message = "	   f-12343g";*/

	/*printf("String is %s, integer is %d\n", message, ft_atoi(message));*/
	/*return (0);*/
/*}*/
