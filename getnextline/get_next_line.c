#include "get_next_line.h"

//CZEGO NIE WIEM
/* 
-  w jaki sposob natknac sie na znak "\n"???
-  czy mozna korzystac z open/ fopen??
-  czy case'a robimy wylacznie dla "\n" i "$"???
-  w jaki spososb zaznaczyc w funkcji read zmieniajacy sie rozmiar buffera z poziomu terminalu??
-  jezeli przypisze zmiennej statyczneej wartosc poza polem inicjalizacji to czy ona będzie się na nią zmieniać?
-  czy moge korzytsac z realloc??
-  get_next_line mamy mieć możliwość wywołać wielokrotnie, czy musimy pisać kod w tym przypadku 
aby to zrobic czy to tylko sie robi na zasadzie testów??
*/

char *get_next_line(int fd)
{
    static int flag; // statyczne zmienne zapamietujace parametry
    //STATYCZNA ZMIENNA DLA LISTY/TABELI
    // tabela albo lista majaca przechowywac pobrany tekst z buffera
    flag = 0;
    // funkcja pewnie w utils otwierajaca file

    //jakas kontrola bledow return -> NuLL

    // petla z read odczytujaca czy plik nie jest skonczony // prawdopodobny warunek dopoki read nie zwraca 0
      // buffer, ktory znajduje się w  ustawiany jest z pola terminalu
        // odczytujemy x znakow
        // wrzucamy je do tabeli/listy
        //sprawdzamy czy nie ma znaku "$" lub "\n"
            // jezeli tak to wypisujemy wers do stringa np. "line"  [albo terminala włączając znak końca linijki]
            // sprzatamy tabele/liste usuwając z niej użytą linijkę - tez pewnie funckja w utils\
            // return get_next_line(line) bo cos zwrocic trzeba
    //

    // jakis Error -> return NUll
    // nothing more to read -> return NULL
}

int main()
{
    int *pointer = (int *)malloc(sizeof(int));
    if (pointer == NULL)
        write(1, "null pointer \n", 14);
    else
        write(1, "gut\n", 4);
    free(pointer);
    return (0);    
}
