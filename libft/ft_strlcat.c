/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:48:25 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/21 00:05:38 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (!src)
		return (ft_strlen(dst));
	while (src[j] && j < (size - ft_strlen(dst) - 1))
		dst[i++] = src[j++];
	dst[i + j] = 0;
	return (ft_strlen(dst));
}
