#include "get_next_line.h"

char	*join_and_free(const char *s1, const char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*get_next_line(int fd) // chyba na razie giit
{
	static char *stash;
	char *display_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_and_find_line(fd, stash);
	if (!stash)
		return (NULL);
	// wiemy ze w stashu jest linia + potencjalnie cos jeszcze
	// funkcja wprowadzajaca dane do linii
	// funkcja usuwajaca ze stash'a wyswietlone juz linie
	free(stash);
	return (display_line);
}

char	*clean_stash_and_return(char *stash)
{
	int		found_after_;
	int		i;
	char	*temp;
	char	*display_line;

	i = 0;
	temp = stash;
	if (!stash)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
	{
		i++;
	}
	display_line = (char *)malloc((ft_strlen(stash) - i) * sizeof(char));
		// do zwryfikwoania
	// temp = ft_strchr(stash, '\n');
	while (temp[i] && temp[i] != '\n')
	{
		display_line[i] = temp[i];
		i++;
	}
}

char	*fill_and_find_line(int fd, char *stash)
{
	int		r;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = join_and_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	if (r == -1)
		return (NULL);
	free(buffer);
	return (stash);
}

// char	*fill_and_find_line(int fd, char *stash)
//{
//	int	r;
//	char	*buffer;
//	char	*temp;

//	//temp = stash;
//	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
//	if (!buffer)
//		return (NULL);
//	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
//	{
//		if (!temp)
//			temp = ft_strdup(buffer);
//		else
//			temp = ft_strjoin(temp, buffer);
//		if (ft_strchr(stash, '\n'))
//			break ;
//	}
//	free(buffer);
//	free(stash);
//	return (temp);
//}

// char	*prepare_outcome(char *stash, int new_line_loc)
//{
//	int		i;
//	char	*display_line;

//	display_line = (char *)malloc((new_line_loc + 1) * sizeof(char));
//	i = 0;
//	while (stash[i] != '\n')
//	{
//		display_line[i] = stash[i];
//		i++;
//	}
//	display_line[i] = stash[i];
//	display_line[++i] = '\0';
//	stash = ft_substr(stash, new_line_loc, ft_strlen(stash));
//	return (display_line);
//}

// int	open_file(const char *fileName) /// dziala milo
//{
//	int file;
//	if ((file = open(fileName, O_RDONLY)) == -1)
//	{
//		write(1, "Cannot open file\n", 17);
//		return (1);
//	}
//	write(1, "File opened\n", 12);
//	return (file); // zwraca fd
//}

int	main(void)
{
	// char filename[] = "/nfs/homes/kkrasnod/student_Projects/github_libft/getnextline/t.txt";
	// -> succes case
	char filename[] = "book.txt"; // fail case -> no such file
	// fd = open_file(filename);
	return (0);
}
