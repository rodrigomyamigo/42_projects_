/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:31:28 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 23:27:00 by kkrasnod         ###   ########.fr       */
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
	j = 0;
	if (!little)
		return ((char *)big);
	while (i < len && big[i] && little[j])
	{
		if (big[i] == little[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (j == count)
		return ((char *)&big[i - count]);
	return (NULL);
}
