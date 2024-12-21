/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:31:28 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/21 03:13:50 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = ft_strlen(little);
	i = 0;
	if (!little)
	{
		return (big);
	}
	while (big[i] && i < len)
	{
		if (big[i] == little[i])
		{
			count--;
			j = i;
			while (big[j])
				if (count == 0)
					return (&little[0]);
		}
		i++;
	}
	return (NULL);
}
