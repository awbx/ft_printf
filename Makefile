NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=src
CFILES=ft_get_address.c \
	   ft_get_char.c \
	   ft_get_number.c \
	   ft_get_percent.c \
	   ft_get_string.c \
	   ft_global_utils.c \
	   ft_parser_utils.c \
	   ft_printf.c \
	   ft_get_unknown.c

OBJ=$(CFILES:%.c=$(SRC)/%.o)
HEADER=$(SRC)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rsc $(NAME) $(OBJ)

$(SRC)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

