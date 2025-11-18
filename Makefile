# Name of the executable
NAME = fdf_obj

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source Files (Inside src/)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object Files (Stored in `obj/`)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra  -g -I./libft -I./minilibx-linux

# Libft and MiniLibX settings
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a
INCLUDES = -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -I$(SRC_DIR)


# X11 and Xext libraries (necessary for MiniLibX)
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd

# Default target
all: $(LIBFT) $(MINILIBX) $(NAME)

# Build the fdf executable (with X11 libraries)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "Executable $(NAME) created."

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build Libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build MiniLibx
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(info SRCS = $(SRCS))


# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re