NAME			:= fdf

CC				:= cc
CFLAGS			:= -g -Wall -Wextra -Werror -lm

LIBFT_DIR		:= ./libft/
LIBFT_DIR_MAIN	:= ./libft/libft/
SRCS_PATH		:= ./srcs/
READER_PATH		:= $(SRCS_PATH)/reader/
DEALLOC_PATH	:= $(SRCS_PATH)/deallocation/
LIBFT			:= $(LIBFT_DIR)/libft.a
LIBMLX			:= ./lib/MLX42
MLX				:= ./lib/MLX42/build/libmlx42.a
LIBMLX_DIR		:= $(LIBMLX)/include
FDF_HEADER		:= fdf.h
LIBFT_HEADER	:= $(LIBFT_DIR)/libft.h
GNL_HEADER		:= $(LIBFT_DIR)/libft/get_next_line.h 

SRCS_READER		:= utils.c map_creation.c reader.c count_rows.c validators.c colour_extractor.c
SRCS_DEALLOC	:= mixed_freers.c matrix_freers.c
MAIN			:= main.c colour_modifier.c draw_wireframe.c colour_interpolation.c utils_core.c actions.c

HEADERS			:= -I$(LIBMLX_DIR) -I$(LIBFT_DIR) -I$(LIBFT_DIR)/libft -I$(LIBFT_DIR)/libft/get_next_line.h
LIB				:= -L$(LIBMLX)/build -lmlx42 -L$(LIBFT_DIR) -lft -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework OpenGL -framework AppKit

OBJS_LIBFT		:= $(SRCS_LIBFT:.c=.o)

OBJS			:= $(addprefix $(LIBFT_DIR_MAIN), $(OBJS_LIBFT))

SRCS			:= $(addprefix $(READER_PATH), $(SRCS_READER)) $(addprefix $(SRCS_PATH), $(MAIN)) $(addprefix $(DEALLOC_PATH), $(SRCS_DEALLOC))

GREEN			:= \033[0;32m
BLUE			:= \033[0;34m
NC				:= \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(HEADERS) $(LIB) -o $(NAME)
	@echo "$(GREEN)Compilation of '$(NAME)' completed successfully$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(GREEN)Library 'libmlx42.a' created$(NC)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(LIBMLX)/build
	@echo "$(BLUE)Cleaned object files from libft and build folder from mlx42$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Removed '$(NAME)'$(NC)"
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)Cleaning finished$(NC)"

re: fclean all
	@echo "$(GREEN)Everything recompiled$(NC)"

.PHONY: all clean fclean re libmlx