/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:44:45 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/18 23:38:41 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchar(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0 && (char)c != s[i])
		i--;
	if ((char)c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}
