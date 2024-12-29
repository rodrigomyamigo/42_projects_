/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:20:20 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 21:44:04 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_in_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		max;
	char	*ptr;

	i = 0;
	j = 0;
	max = ft_strlen(s1);
	while (s1[i] && find_in_set(s1[i], set))
		i++;
	while (max > i && find_in_set(s1[max - 1], set))
		max--;
	ptr = (char *)malloc((max - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < max)
		ptr[j++] = s1[i++];
	ptr[j] = 0;
	return (ptr);
}
