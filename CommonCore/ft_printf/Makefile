FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_u.c ft_putlhex.c ft_putuhex.c ft_putptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
