/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:49 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/04/07 15:08:55 by kkrasnod         ###   ########.fr       */
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
	if (!display_line)
		return (NULL);
	stash = clean_stash(stash);
	return (display_line);
}

char	*fill_and_find_newline(int fd, char *stash)
{
	char	*buffer;
	int		r;

	//buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = join_and_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}
	//buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	//buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));

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

	len = 0;
	while (stash[len])
		len++;
	new_start = 0;
	if (!stash)
		return (NULL);
	while (stash[new_start] && stash[new_start] != '\n')
		new_start++;
	if (!stash[new_start])
	{
		free(stash);
		return (NULL);
	}
	if (stash[new_start] == '\n')
		new_start++;
	temp = ft_substr(stash, new_start, len);
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

//void	*ft_calloc(size_t count, size_t size)
//{
//	void	*ptr;
//	size_t	i;

//	i = 0;
//	ptr = malloc(count * size);
//	if (!ptr)
//		return (NULL);
//	while (i < count * size)
//	{
//		((unsigned char *)ptr)[i] = 0;
//	}
//	return (ptr);
//}

//display_line = clean_stash_return_line(stash);
//char	*clean_stash_return_line(char *stash)
//{
//	int		len;
//	int		new_loc;
//	char	*temp;
//	char	*display_line;

//	if (!stash)
//		return (NULL);
//	len = ft_strlen(stash);
//	new_loc = 0;
//	while (stash[new_loc] && stash[new_loc] != '\n')
//		new_loc++;
//	display_line = (char *)malloc((new_loc + 2) * sizeof(char));
//	temp = ft_substr(stash, new_loc, len);
//	if (!temp)
//		return (NULL);
//	free(stash);
//	new_loc = 0;
//	while (temp[new_loc] && temp[new_loc] != '\n')
//	{
//		display_line[new_loc] = temp[new_loc];
//		new_loc++;
//	}
//	display_line[new_loc] = '\0';
//	stash = temp;
//	return (display_line);
//}

 int	open_file(const char *fileName) /// dziala milo
{
	int file;
	if ((file = open(fileName, O_RDONLY)) == -1)
	{
		write(1, "Cannot open file\n", 17);
		return (1);
	}
	write(1, "File opened\n", 12);
	return (file); // zwraca fd
}

// int	main(void)
//{
//	char filename[] ="/nfs/homes/kkrasnod/student_Projects/github_libft/getnextline/t.txt";
//	// -> succes case
//	// char filename[] = "book.txt"; // fail case -> no such file
//	int fd = open_file(filename);
//	char *line;
//	int fd1;
//	int fd2;

//	return (0);
//}