/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:01:52 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/14 23:52:58 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_undecimal(unsigned int u)
{
	unsigned int	temp;
	int				count;
	int				lenght;
	char			buffer[12];

	count = 0;
	temp = u;
	if (temp == 0)
		return (write(1, "0", 1));
	while (temp > 0)
	{
		buffer[count++] = (temp % 10) + '0';
		temp /= 10;
	}
	lenght = count;
	while (--lenght >= 0)
		write(1, &buffer[lenght], 1);
	return (count);
}

int	print_heximal_small(int x)
{
	char			*hex;
	char			buffer[16];
	unsigned int	temp;
	int				lenght;
	int				count;

	count = 0;
	hex = "0123456789abcdef";
	temp = (unsigned)x;
	if (temp == 0)
		return (write(1, "0", 1));
	while (temp > 0)
	{
		buffer[count++] = hex[temp % 16];
		temp /= 16;
	}
	lenght = count;
	while (--lenght >= 0)
		write(1, &buffer[lenght], 1);
	return (count);
}

int	print_heximal_large(int X)
{
	char			*hex;
	char			buffer[16];
	unsigned int	temp;
	int				lenght;
	int				count;

	count = 0;
	hex = "0123456789ABCDEF";
	temp = (unsigned)X;
	if (temp == 0)
		return (write(1, "0", 1));
	while (temp > 0)
	{
		buffer[count++] = hex[temp % 16];
		temp /= 16;
	}
	lenght = count;
	while (--lenght >= 0)
		write(1, &buffer[lenght], 1);
	return (count);
}

int	check_next_char(va_list args, const char *s, int i)
{
	if (s[i] == 'c')
		return (print_char(va_arg(args, int)));
	if (s[i] == 's')
		return (print_string(va_arg(args, char *)));
	if (s[i] == 'p')
		return (print_pointer((unsigned long)va_arg(args, void *)));
	if (s[i] == 'd' || s[i] == 'i')
		return (print_decimal(va_arg(args, int)));
	if (s[i] == 'u')
		return (print_undecimal(va_arg(args, unsigned int)));
	if (s[i] == 'x')
		return (print_heximal_small(va_arg(args, int)));
	if (s[i] == 'X')
		return (print_heximal_large(va_arg(args, int)));
	if (s[i] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += check_next_char(args, s, i);
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
