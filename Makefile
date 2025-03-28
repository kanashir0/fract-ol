# Compiler vars
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
MLXFLAGS = MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# Sources and objects vars
FRACTOL_SRC = main.c init.c render.c math_utils.c events.c

FRACTOL_OBJ = $(FRACTOL_SRC:.c=.o)

FRACTOL_BIN = fractol

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Commands
all: $(LIBFT) $(PRINTF) $(FRACTOL_BIN)

$(FRACTOL_BIN): $(FRACTOL_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(FRACTOL_OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(FRACTOL_BIN)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re