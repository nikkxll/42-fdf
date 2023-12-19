NAME = libft.a

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/
	@$(MAKE) bonus -C libft/
	@echo "$(GREEN)Function GNL and libft added to the new library$(NC)"
	@echo "$(GREEN)Library 'libft.a' created$(NC)"

clean:
	@$(MAKE) clean -C libft/

fclean: clean
	@-rm -f $(NAME)
	@$(MAKE) -C libft/ fclean
	@echo "$(BLUE)Removed '$(NAME)'$(NC)"

re: fclean all

.PHONY: all, clean, fclean, re