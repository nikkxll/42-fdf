NAME			:= fdf

CC				:= cc
CFLAGS			:= -g -Wall -Wextra -Werror

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

SRCS_LIBFT		:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
  get_next_line.c get_next_line_utils.c

SRCS_READER		:= utils.c map_creation.c reader.c count_rows.c validators.c colour_extractor.c
SRCS_DEALLOC	:= mixed_freers.c matrix_freers.c
MAIN			:= main.c

HEADERS			:= -I$(LIBMLX_DIR) -I$(LIBFT_DIR) -I$(LIBFT_DIR)/libft -I$(LIBFT_DIR)/libft/get_next_line.h
LIB				:= -L$(LIBMLX)/build -lmlx42 -L$(LIBFT_DIR) -lft -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework OpenGL -framework AppKit

OBJS_LIBFT		:= $(SRCS_LIBFT:.c=.o)

OBJS			:= $(addprefix $(LIBFT_DIR_MAIN), $(OBJS_LIBFT))

SRCS			:= $(addprefix $(READER_PATH), $(SRCS_READER)) $(addprefix $(LIBFT_DIR_MAIN), $(SRCS_LIBFT)) \
  $(addprefix $(SRCS_PATH), $(MAIN)) $(addprefix $(DEALLOC_PATH), $(SRCS_DEALLOC))

GREEN			:= \033[0;32m
BLUE			:= \033[0;34m
NC				:= \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(HEADERS) $(LIB) -o $(NAME)
	@echo "$(GREEN)✅ Compilation of '$(NAME)' completed successfully$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(LIBMLX)/build
	@echo "$(BLUE)🧹 Cleaned object files from libft and build folder from mlx42$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)🧹 Removed '$(NAME)'$(NC)"
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)✅ Cleaning finished$(NC)"

re: fclean all
	@echo "$(GREEN)🚀 Everything recompiled$(NC)"

.PHONY: all clean fclean re libmlx