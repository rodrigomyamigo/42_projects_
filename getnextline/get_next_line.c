#include "get_next_line.h"

// CZEGO NIE WIEM
/*
-  jezeli przypisze zmiennej statyczneej wartosc poza polem inicjalizacji to czy ona będzie się na nią zmieniać?
-  czy moge korzytsac z realloc??
-  get_next_line mamy mieć możliwość wywołać wielokrotnie,
	czy musimy pisać kod w tym przypadku
aby to zrobic czy to tylko sie robi na zasadzie testów??
*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*display_line;

	int new_line_loc; // change
	// stash alokowanie  display_line
	// czy fd istnieje
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// inicjalizuje stash z jakim rozmiarem?? --> buffersize aby bylo w stanie pobrac pierwszy read()
	stash = (char *)malloc(BUFFER_SIZE * sizeof(char));
	// ma miejsce na pierwsze pobranie przez buffer
	if (!stash)
		// czy stash jest poprawnie zainicjalizowany
		return (NULL);
	stash = fill_and_find_line(fd, stash);
	// wiemy ze w stashu jest linia + potencjalnie cos jeszcze
	prepare_outcome(stash, new_line_loc);
	free(stash);
	return (display_line);
}

char	*prepare_outcome(char *stash, int new_line_loc)
{
	int		i;
	char	*display_line;

	display_line = (char *)malloc((new_line_loc + 1) * sizeof(char));
	i = 0;
	while (stash[i] != '\n')
	{
		display_line[i] = stash[i];
		i++;
	}
	display_line[i] = stash[i];
	display_line[++i] = '\0';
	stash = ft_substr(stash, new_line_loc, ft_strlen(stash));
	return (display_line);
}

int	fill_and_find_line(int fd, char *stash)
{
	int		r;
	int		new_line_loc;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!stash)
			stash = strdup(buffer);
		else
			stash = str_join(stash, buffer);
		if (new_line_loc = ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (new_line_loc);
}

/*char	*fill_and_find_line(int fd, char *stash)
{
	int		r;
	char	*buffer;
	int		fd;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!stash)
			stash = strdup(buffer);
		else
			stash = str_join(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}*/
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
