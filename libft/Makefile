NAME = libft.a

# Source files
SOURCES = \
	ft_atoi.c ft_isascii.c  ft_memset.c ft_split.c ft_strmapi.c \
	ft_toupper.c ft_bzero.c ft_isdigit.c  ft_putchar_fd.c  ft_strdup.c \
	ft_strnstr.c ft_calloc.c ft_isprint.c  ft_putendl_fd.c \
	ft_strtrim.c ft_isalnum.c ft_itoa.c  ft_putnbr_fd.c ft_striteri.c \
	ft_substr.c ft_isalpha.c  ft_memcpy.c ft_putstr_fd.c ft_strjoin.c \
	ft_tolower.c ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_strchr.c \
	ft_strncmp.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_printf.c print_functions.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstclear.c ft_lstnew.c ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstlast.c ft_lstsize.c \

	
	
# Object files
OBJECTS = $(SOURCES:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $(OBJECTS)


# Compile source files into object files
%.o: %.c libft.h
	$(CC) -c $(CFLAGS) $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS) $

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all bonus clean fclean re
