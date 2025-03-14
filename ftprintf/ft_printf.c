/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:01:52 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/14 23:31:20 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

// int	check_next_char(va_list args, const char *s, int i)
//{
//	if (s[i] == 'c')
//		return (print_char(va_arg(args, int)));
//	if (s[i] == 's')
//		return (print_string(va_arg(args, char *)));
//	if (s[i] == 'p')
//		return (print_pointer((unsigned long)va_arg(args, void *)));
//	if (s[i] == 'd')
//		return (print_decimal(va_arg(args, int)));
//	if (s[i] == 'i')
//		return (print_integer(va_arg(args, int)));
//	if (s[i] == 'u')
//		return (print_undecimal(va_arg(args, unsigned int)));
//	if (s[i] == 'x')
//		return (print_heximal_small(va_arg(args, int)));
//	if (s[i] == 'X')
//		return (print_heximal_large(va_arg(args, int)));
//	if (s[i] == '%')
//		return (write(1, '%%', 1));
//	return (0);
//}

// int	ft_printf(const char *s, ...)
//{
//	int		count;
//	va_list	args;
//	int		i;

//	count = 0;
//	i = 0;
//	va_start(args, s);
//	while (s[i])
//	{
//		if (s[i] == '%')
//		{
//			i++;
//			count += check_next_char(args, s[i], i);
//		}
//		else
//		{
//			write(1, s[i], 1);
//			count++;
//		}
//		i++;
//	}
//	va_end(args);
//	return (count);
//}

// int	print_char(int c)
//{
//	write(1, &c, 1);
//	return (1);
//}

// int	print_string(char *c)
//{
//	int	count;

//	count = 0;
//	while (c[count])
//		write(1, c[count++], 1);
//	return (count);
//}

// int	print_pointer(void *ptr)
//{
//	int				count;
//	char			*base;
//	char			hex[17];
//	unsigned int	ui;
//	int				i;

//	ui = (unsigned int)ptr;
//	base = "0123456789abcdef";
//	i = 16;
//	count = 0;
//	if (ptr == 0)
//	{
//		count += write(1, "(nil)", 5);
//		return (5);
//	}
//	count += write(1, "0x", 2);
//	hex[16] = '\0';
//	while (ui > 0)
//	{
//		hex[--i] = base[ui % 16];
//		ui /= 16;
//	}
//	count += write(1, &hex[i], 16 - i);
//	return (count);
//}

// int	print_decimal(int c)
//{
//	int temp;
//	int count;
//	int length;
//	char buffer[20];

//	count = 0;
//	if (c == 0)
//		buffer[count++] = '0';

//	if (c < 0)
//	{
//		write(1, '-', 1);
//		c = -c;
//	}

//	temp = c;
//	while (temp > 0)
//	{
//		buffer[count++] = (temp % 10) + '0';
//		temp = temp / 10;
//	}
//	length = count;
//	while (--length >= 0)
//		write(1, &buffer[length], 1);
//	return (count);

///*

//*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:30 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/09 16:54:14 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

#include <unistd.h>

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

int	print_undecimal(unsigned int u)
{
	unsigned	temp;
	int			count;
	int			lenght;
	char		buffer[12];

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
	// if (s[i] == 'i')
	//	return (print_integer(va_arg(args, int)));
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

// int	main(void)
//{
//	ft_printf("moje %p", "test");
//	printf("\n%p\n", "test");
//	return (0);
//}