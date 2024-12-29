/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:48:25 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 23:25:06 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = -1;
	if (size <= len_dest)
		return (len_src + size);
	while (src[++i] && i < (size - len_dest - 1))
		dst[i + len_dest] = src[i];
	dst[i + len_dest] = 0;
	return (len_dest + len_src);
}
