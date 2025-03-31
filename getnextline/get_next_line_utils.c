/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:45:18 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/03/31 21:36:30 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while((char) c != s[i] && s[i])
		i++;
	if ((char)c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}

char *ft_strdup(const char *s)
{
	char	*dup;
	int	i;

	i = 0;
	while(s[i])
		i++;
	dup = (char *)malloc((i+1) * sizeof(char));
	if(!dup)
	{
	    printf("Memory allocated incorrectly.\n");
	    return (NULL);
	}
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
