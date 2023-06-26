NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr\
	ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strcntchr ft_strrchr\
	ft_substr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_putnbr_base_fd\
	ft_putunsigned_fd ft_putunsigned_base_fd ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit\
	ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc ft_strdup\
	ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_itoa ft_itoa_base\
	ft_utoa ft_utoa_base ft_ultoa_base ft_split ft_charinset\
	ft_printf ft_printf_buffer ft_printf_chr ft_printf_hex ft_printf_int ft_printf_pointer ft_printf_str ft_printf_uns
	
BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
		ft_lstdelone ft_lstclear ft_lstiter ft_lstmap


all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $^

.PHONY: clean fclean re all bonus

bonus:  $(BONUS:=.o) $(NAME)
	ar rcs $(NAME) $(BONUS:=.o)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
