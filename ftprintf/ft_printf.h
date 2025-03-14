/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:47:04 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/01/11 21:26:09 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //va_start
# include <stdlib.h> //malloc
# include <unistd.h>

int	ft_printf(const char *s, ...);

int	check_next_char(va_list args, const char *c, int a);

#endif