NAME = fdf

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT_DIR_MAIN = ./libft/libft/
SRCS_PATH = ./srcs/
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
  ft_atoi.c ft_calloc.c ft_strdup.c \
  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
  get_next_line.c get_next_line_utils.c

SRCS_FDF = freers.c utils.c main.c map_creation.c reader.c count_rows.c

HEADER = fdf.h
HEADER_LIBFT = libft/libft.h
HEADER_GNL = libft/libft/get_next_line.h

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

OBJS = $(addprefix $(LIBFT_DIR_MAIN), $(OBJS_LIBFT))

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FDF)) $(addprefix $(LIBFT_DIR_MAIN), $(SRCS_LIBFT))

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(OBJS) $(LIBFT) $(HEADER) $(HEADER_LIBFT) $(HEADER_GNL)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ Compilation of '$(NAME)' completed successfully$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -f $(NAME)
	@echo "$(BLUE)🧹 Removed '$(NAME)'$(NC)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(GREEN)🚀 Everything recompiled$(NC)"

.PHONY: all clean fclean re