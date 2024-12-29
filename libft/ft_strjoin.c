/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:10:11 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 21:19:24 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len_s1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		ptr[len_s1 + i] = s2[i];
	ptr[len_s1 + i] = 0;
	return (ptr);
}
