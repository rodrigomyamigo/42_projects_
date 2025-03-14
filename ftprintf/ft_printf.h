/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:47:04 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/14 23:40:09 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //va_start
# include <stdlib.h> //malloc
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	check_next_char(va_list args, const char *c, int a);
int	print_heximal_large(int X);
int	print_heximal_small(int x);
int	print_char(int c);
int	print_string(char *s);
int	print_pointer(unsigned long ptr);
int	print_decimal(int c);
int	print_undecimal(unsigned int u);

#endif