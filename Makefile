NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
	
all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(NAME): *.o $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^
	
$(LIBFT):
	@$(MAKE) -C libft bonus
	@cp libft/libft.a .
	@cp libft/libft.h .
	@echo "$(GREEN)libft.a compiled and imported"

.PHONY: clean fclean re all bonus

bonus: re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f libft.h
ifneq (,$(wildcard libft/))
	$(MAKE) -C libft fclean
endif

re: fclean all