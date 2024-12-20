/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:31:20 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/18 23:39:10 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchar(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)c != s[i] && s[i])
		i++;
	if ((char)c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}