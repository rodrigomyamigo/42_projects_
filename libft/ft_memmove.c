/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:57:21 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 23:15:03 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr_src;

	ptr = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (ptr == ptr_src || n == 0)
		return (dest);
	if (ptr > ptr_src)
		while (n--)
			ptr[n] = ptr_src[n];
	else
		while (n--)
			*ptr++ = *ptr_src++;
	return (dest);
}
