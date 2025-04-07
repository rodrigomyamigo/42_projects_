/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:45:18 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/04/07 16:07:42 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)c != s[i] && s[i])
		i++;
	if ((char)c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
	{
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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	size_t			s_len;
	char			*sub_s;

	s_len = ft_strlen(s);
	j = 0;
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[start] && j < len)
		sub_s[j++] = s[start++];
	sub_s[j] = 0;
	return (sub_s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_s;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined_s)
		return (NULL);
	while (s1[i])
		joined_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined_s[j++] = s2[i++];
	joined_s[j] = '\0';
	return (joined_s);
}
