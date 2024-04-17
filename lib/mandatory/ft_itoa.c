/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:45 by jcummins          #+#    #+#             */
/*   Updated: 2023/11/21 20:35:26 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_digits(unsigned int n)
{
	unsigned int	digits;

	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

unsigned int	absolute(int n)
{
	unsigned int	abs;

	abs = 0;
	if (n < 0)
		abs = -n;
	else
		abs = n;
	return (abs);
}

char	*printstr(char *s, unsigned int n, int neg)
{
	int	i;

	i = (n_digits(n));
	s[i-- + neg] = '\0';
	while (i >= 0)
	{
		s[i + neg] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				neg;
	unsigned int	num;

	neg = 0;
	if (n < 0)
		neg = 1;
	num = absolute(n);
	str = (char *)malloc((n_digits(num) + 1 + neg) * sizeof(char));
	if (!str)
		return (NULL);
	printstr(str, num, neg);
	return (str);
}

/*int	main(void)*/
/*{*/
	/*int	i;*/

	/*i = -2147483648;*/
	/*printf("The number %d as a string is %s\n", i, ft_itoa(i));*/
	/*return (0);*/
/*}*/
