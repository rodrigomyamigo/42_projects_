/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:21:11 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/24 01:55:46 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size >= SIZE_MAX / nmemb)
		return (NULL);
	if (size == 0 && nmemb == 0)
		ptr = (unsigned char *)malloc(nmemb * size);
	else if (size == 0 || nmemb == 0)
		return (ptr);
	ptr = (unsigned char *)malloc(nmemb * size);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
