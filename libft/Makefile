NAME = libft.a

SRC = ft_atoi.c ft_isascii.c ft_memset.c ft_strlcpy.c ft_tolower.c \
	ft_bzero.c ft_istdigit.c ft_print.c ft_strlen.c ft_toupper.c \
	ft_calloc.c ft_memchr.c ft_strchr.c ft_strncmp.c \
	ft_isalnum.c ft_memcpy.c ft_strdup.c ft_strnstr.c \
	ft_isalpha.c ft_memmove.c ft_strlcat.c ft_strrchr.c ft_memcmp.c

FLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
CC = cc
RM = rm -f


OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
#phonii?