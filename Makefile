# Compiler vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
# MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

# Sources and objects vars
FRACTOL_SRC = main.c init.c render.c math_utils.c events.c

FRACTOL_OBJ = $(FRACTOL_SRC:.c=.o)

FRACTOL_BIN = fractol

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a

# Commands
all: $(LIBFT) $(PRINTF) $(FRACTOL_BIN) $(MLX)

$(FRACTOL_BIN): $(FRACTOL_OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4

clean:
	rm -f $(FRACTOL_OBJ)
	rm -rf $(MLX)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(FRACTOL_BIN)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re