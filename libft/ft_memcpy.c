/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:37:33 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/24 02:52:29 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	while (n--)
	{
		*ptr++ = *src_ptr++;
	}
	return (dest);
}
