# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 10:45:06 by ael-mank          #+#    #+#              #
#    Updated: 2024/01/23 18:38:53 by ael-mank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME          = so_long
INCLUDE       = include
MLX_DIR       = minilibx-linux
MLX           = mlx_Linux
SRC_DIR       = src/
OBJ_DIR 	  = obj/
CC            = cc
# CFLAGS        = -Wall -Werror -Wextra -Ilibft/include -I$(MLX_DIR) -I$(INCLUDE)
CFLAGS        = -Wall -Werror -Wextra -Ilibft/include -I$(MLX_DIR) -I$(INCLUDE) -O3
CFLAGS        += -Llibft -L$(MLX_DIR) -lft -lX11 -lXext -l$(MLX)
DEBUG_FLAGS   = -g
RM            = rm -f
MAKE := make

GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
NC=\033[0m

# Sources Push_Swap
SRC_FILES = main moove end base map_handling map_handling2 draw collectibles frames
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ_PS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

.PHONY: all clean fclean re help debug norm so_long

# Rules
all:
	@cd $(MLX_DIR) && ./configure > /dev/null 2>&1 
	@echo "$(GREEN)Built MiniLibX ✅ $(NC)"
	@cd ./libft && make > /dev/null && make bonus > /dev/null && make printf > /dev/null
	@echo "$(GREEN)Built Libft ✅ $(NC)"
	@$(MAKE) -s $(NAME)

so_long: $(OBJ_PS)
	@$(CC) -Llibft -L$(MLX_DIR) -o $@ $^ $(CFLAGS) -lX11 -lXext -l$(MLX) -lft
	@echo "$(BLUE)Compiled $(NAME) 🎮 $(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $< into $@ $(NC)"

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
	@echo "$(BLUE)Cleaned and recompiled $(NAME) 🔁 $(NC)"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

norm:
	@norminette */* | grep -v Norme -B1 || true

help:
	@echo "Available targets:"
	@echo "  $(BLUE)all$(NC)   : Build the project"
	@echo "  $(BLUE)clean$(NC) : Remove object files"
	@echo "  $(BLUE)fclean$(NC): Remove object files and the executable"
	@echo "  $(BLUE)re$(NC)    : Rebuild the project"
	@echo "  $(BLUE)debug$(NC) : Build the project with debug flags"
	@echo "  $(BLUE)norm$(NC)  : Check the norm of the project"
