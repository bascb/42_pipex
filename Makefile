NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = pipex pipex_utils
LIBFT = libft.a

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
	
all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC:=.o) $(LIBFT)
	
$(LIBFT):
	@$(MAKE) -C libft bonus
	@cp libft/libft.a .
	@cp libft/libft.h .
	@echo "libft.a compiled and imported"

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

.PHONY: clean fclean re all