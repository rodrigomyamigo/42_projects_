#include "get_next_line.h"

// CZEGO NIE WIEM
/*
-  w jaki sposob natknac sie na znak "\n"???
-  czy mozna korzystac z open/ fopen??
-  czy case'a robimy wylacznie dla "\n" i "$"??? --> "\n" i "\0"
-  w jaki spososb zaznaczyc w funkcji read zmieniajacy sie rozmiar buffera z poziomu terminalu??
-  jezeli przypisze zmiennej statyczneej wartosc poza polem inicjalizacji to czy ona będzie się na nią zmieniać?
-  czy moge korzytsac z realloc??
-  get_next_line mamy mieć możliwość wywołać wielokrotnie,
	czy musimy pisać kod w tym przypadku
aby to zrobic czy to tylko sie robi na zasadzie testów??
*/

char	*get_next_line(int fd)
{
	int			bytesRead;
	char		*display_line;
	int			i;
	static int	cursor;
	int			n;

	// statyczne zmienne zapamietujace parametry
	// STATYCZNA ZMIENNA DLA LISTY/TABELI
	char *file_name;    // path or fd type
	static char *stash; // store data read by buffor
	char *buffer;       // buffor
	// tabela albo lista majaca przechowywac pobrany tekst z buffera
	n = 30;
	cursor = 0;
	buffer = 5;
	fd = open_file(file_name);
	stash = (char *)malloc(n * sizeof(char));
	// test
	if (!stash) // czy dobrze allokuje pamiec
	{
		write(1, "Memory not allocated correctly", 30);
	}
	while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
	// petla z read odczytujaca czy plik nie jest skonczony
	// prawdopodobny warunek dopoki read nie zwraca 0
	// buffer, ktory znajduje się w  ustawiany jest z pola terminalu
	// odczytujemy x znakow
	{
		i = 0;
		while (i < sizeof(buffer))
			stash[cursor] = buffer[i++];
	}
	// wrzucamy je do tabeli/listy
	// sprawdzamy czy nie ma znaku "$" lub "\n"
	// jezeli tak to wypisujemy wers do stringa np. "line"  [albo terminala włączając znak końca linijki]
	// sprzatamy tabele/liste usuwając z niej użytą linijkę
	//- tez pewnie funckja w utils\
            // return get_next_line(line) bo cos zwrocic trzeba
	return (display_line);
	//
	// jakis Error -> return NUll
	// nothing more to read -> return NULL
}

char	*get_next_line(int fd)
{
	char		*display_line;
	char		*buffer;
	static char	*stash;
	char		*path;
	size_t		arr_size;

	arr_size = 30;
	fd = open_file(path);
	buffer = (char *)malloc(arr_size * sizeof(char));
	if (!buffer)
		return (NULL);
	// other checks
	// tash = _fill_line_buffer(fd, , buffer);
	// wyczysc buffor free
}

char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	int		r;
	int		i;
	size_t	len;

	// read na pewno
	i = 0;
	while ((r = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (!left_c)
			left_c = strdup(buffer);
	}
	left_c = str_join(left_c, buffer);
	/*
	if (len < ft_strlen(left_c) + ft_strlen(buffer))
	{
		len = 2 * (ft_strlen(left_c) + ft_strlen(buffer));
		left_c = realloc(left_c, len * sizeof(char));
	}
	*/
}

char	*_set_line(char *line_buffer)
{
}

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

int	main(void)
{
	int	fd;

	// char filename[] = "/nfs/homes/kkrasnod/student_Projects/github_libft/getnextline/t.txt";
	// -> succes case
	char filename[] = "book.txt"; // fail case -> no such file
	fd = open_file(filename);
	return (0);
}
