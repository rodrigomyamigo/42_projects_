/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:37:33 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 23:12:35 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (!ptr && !src_ptr)
		return (NULL);
	while (n--)
		*ptr++ = *src_ptr++;
	return (dest);
}
