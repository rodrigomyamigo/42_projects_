/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:49 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/04/07 16:08:53 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*display_line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_and_find_newline(fd, stash);
	if (!stash)
		return (NULL);
	display_line = return_line(stash);
	stash = clean_stash(stash);
	if (!display_line)
	{
		free(stash);
		return (NULL);
	}
	return (display_line);
}

char	*fill_and_find_newline(int fd, char *stash)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = join_and_free(stash, buffer);
		if (!stash || ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*clean_stash(char *stash)
{
	int		new_start;
	char	*temp;
	int		len;

	if (!stash)
		return (NULL);
	new_start = 0;
	while (stash[new_start] && stash[new_start] != '\n')
		new_start++;
	if (!stash[new_start])
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen(stash);
	temp = ft_substr(stash, new_start + 1, len);
	if (!temp)
		return (NULL);
	free(stash);
	return (temp);
}

char	*return_line(char *stash)
{
	int		i;
	char	*display_line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	display_line = (char *)malloc((i + 2) * sizeof(char));
	if (!display_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		display_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		display_line[i] = stash[i];
		i++;
	}
	display_line[i] = '\0';
	return (display_line);
}
#include <stdio.h>
 int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	line  = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line  = get_next_line(fd);

	}
	close(fd);
	free(line);
	return (0);
}
