NAME = libftprintf.a

CC = cc                # Common practice is to use `cc` or `gcc` for the compiler

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs            # Command to create a static library

SRC = ft_printf.c      # Source files

OBJ = $(SRC:.c=.o)     # Object files (.c -> .o)

# The all rule is the default target when running `make` without arguments
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the object files
clean:
	rm -f $(OBJ)

# Clean both object files and the static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything (clean, then all)
re: fclean all

