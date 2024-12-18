/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:57:21 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/18 01:47:21 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr_src;

	ptr = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	while (n--)
	{
		if (ptr > ptr_src)
			*ptr++ = *ptr_src++;
		else
			ptr[n] = ptr_src[n];
	}
	return (dest);
}
