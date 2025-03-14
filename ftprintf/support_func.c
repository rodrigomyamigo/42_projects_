/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:47:01 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/14 23:48:58 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[count])
		write(1, &s[count++], 1);
	return (count);
}

int	print_pointer(unsigned long ptr)
{
	int				count;
	char			*base;
	char			hex[17];
	unsigned long	ui;
	int				i;

	ui = ptr;
	base = "0123456789abcdef";
	i = 16;
	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	hex[16] = '\0';
	while (ui > 0)
	{
		hex[--i] = base[ui % 16];
		ui /= 16;
	}
	count += write(1, &hex[i], 16 - i);
	return (count);
}

int	print_decimal(int c)
{
	int		count;
	int		length;
	char	buffer[12];

	count = 10;
	length = 0;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c == 0)
		return (write(1, "0", 1));
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
		length++;
	}
	buffer[11] = '\0';
	while (c)
	{
		buffer[count--] = (c % 10) + '0';
		c /= 10;
	}
	length += write(1, &buffer[count + 1], 10 - count);
	return (length);
}
