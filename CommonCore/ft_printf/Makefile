FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_putchar.c ft_putnbr.c ft_putstr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libftprintf.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
