#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> /// library ffor handling files --> open

char *get_next_line(int fd);
int open_file(char* fd);
