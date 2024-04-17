/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cformats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:21 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/15 19:29:03 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i = print_str("(null)");
	else
		while (str[i])
			write (1, &str[i++], 1);
	return (i);
}

int	print_char(char chr)
{
	write (1, &chr, 1);
	return (1);
}
