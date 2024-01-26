# Variables
CC = gcc
SRC_DIR = ./src/
OBJ_DIR = ./obj/
MLX_DIR = ./minilibx-linux/
MLX     = mlx_Linux
CFLAGS = -Wall -Wextra -Werror -Ilibft/include -I$(MLX_DIR) -Iinclude
SRC_FILES = main moove end base map_handling map_handling2 draw collectibles frames creates flood_fill ennemy render_frame max_gh_gw
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
NAME = so_long
MAKE := make

GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
NC=\033[0m

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@cd $(MLX_DIR) && ./configure > /dev/null 2>&1 
	@echo "$(GREEN)Built MiniLibX ✅ $(NC)"
	@cd ./libft && $(MAKE) > /dev/null && $(MAKE) bonus > /dev/null && $(MAKE) printf > /dev/null
	@echo "$(GREEN)Built Libft ✅ $(NC)"
	@$(CC) -Llibft -L$(MLX_DIR) -o $@ $^ -lft -lmlx $(CFLAGS) -lX11 -lXext
	@echo "$(BLUE)Compiled $(NAME) 🎮 $(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(MAGENTA)Cleaned object files ✅ $(NC)"

fclean: clean
	@cd ./libft && $(MAKE) fclean > /dev/null
	@echo "$(MAGENTA)Cleaned libft ❎ $(NC)"
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@echo "$(MAGENTA)Cleaned mlx ❎ $(NC)"
	@$(RM) -f $(NAME)
	@echo "$(MAGENTA)Cleaned $(NAME) ❎ $(NC)"

re: fclean all