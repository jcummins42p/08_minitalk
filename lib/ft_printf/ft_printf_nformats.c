/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nformats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:29:34 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/15 20:18:22 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int num)
{
	int	i;

	i = 1;
	if (num == -2147483648)
		i = print_str("-2147483648");
	else
	{
		if (num < 0)
		{
			print_char('-');
			num = -num;
			i++;
		}
		if (num >= 10)
		{
			i += print_int(num / 10);
		}
		print_char((num % 10) + '0');
	}
	return (i);
}

int	print_usi(unsigned int num)
{
	int	i;

	i = 1;
	if (num >= 10)
	{
		i += print_int(num / 10);
	}
	print_char((num % 10) + '0');
	return (i);
}

int	print_hex_ptr(unsigned long long num, int cap)
{
	int			i;
	int			print;

	i = 1;
	if (num >= 16)
		i += print_hex_ptr(num / 16, cap);
	print = num % 16;
	if (print < 0)
		print = -print;
	if (!cap)
		print_char("0123456789abcdef"[num % 16]);
	if (cap)
		print_char("0123456789ABCDEF"[num % 16]);
	return (i);
}

int	print_hex(unsigned int num, int cap)
{
	int			i;
	int			print;

	i = 1;
	if (num >= 16)
		i += print_hex(num / 16, cap);
	print = num % 16;
	if (print < 0)
		print = -print;
	if (!cap)
		print_char("0123456789abcdef"[num % 16]);
	if (cap)
		print_char("0123456789ABCDEF"[num % 16]);
	return (i);
}

int	print_ptr(void *ptr)
{
	int		i;

	i = 0;
	if (!ptr)
		i += print_str("(nil)");
	else
	{
		i += print_str("0x");
		i += print_hex_ptr((unsigned long long)ptr, 0);
	}
	return (i);
}
