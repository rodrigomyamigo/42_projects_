/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:38:27 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/18 01:33:19 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*memset(void *s, int c, size_t n);
void	*memcpy(void *dest, const void *src, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
