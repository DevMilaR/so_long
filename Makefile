NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -lXext -lX11 -lm -lbsd
RM = rm -f

#colors 
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0m

SRC_FILES = srcs/main.c srcs/read_map.c srcs/check_map_utils.c \
			srcs/check_img_utils.c srcs/error.c srcs/game_verification.c \
			srcs/image_utils.c srcs/player_utils.c srcs/windows_management.c 

OBJS = $(SRC_FILES:.c=.o)

LIBFT = srcs/libft
MINILIBX = srcs/mlx

LIBS = $(MINILIBX)/libmlx.a $(MLX) $(LIBFT)/libft.a

all: minilibx libft $(NAME)

$(NAME):$(OBJS)
		@echo "$(YELLOW)Linking object files...$(NC)"
		$(CC) $(OBJS) $(LIBS) -o $(NAME)
		@echo "$(GREEN)Executable $(NAME) created!$(NC)"
	
%.o: %.c
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(GREEN)Compiled! $<$(NC)"
	
libft:
	@echo "$(YELLOW)Compiling LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT has been Compiled$(NC)"

minilibx:
	@echo "$(YELLOW)Compiling MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX has been Compiled$(NC)"

fclean_mlx:
	@make fclean -C ./$(MINILIBX)
	@echo "$(RED)MINILIBX cleaned!$(NC)"

fclean_libft:
	@make fclean -C ./$(LIBFT)
	@echo "$(RED)LIBFT cleaned!$(NC)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)OBJS cleaned!$(NC)"

fclean: clean  fclean_libft fclean_mlx
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE cleaned!$(NC)"


re: fclean all

.PHONY: all clean fclean re
