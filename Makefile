NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=src
INCLUDE=include
HEADER=$(INCLUDE)/ft_printf.h
COMMON_FILES=ft_get_address.c \
	   ft_get_char.c \
	   ft_get_number.c \
	   ft_get_percent.c \
	   ft_get_string.c \
	   ft_global_utils1.c \
	   ft_global_utils2.c \
	   ft_global_utils3.c \
	   ft_parser_utils.c \
	   ft_get_unknown.c

MFILES=$(COMMON_FILES) ft_printf.c
BFILES=$(COMMON_FILES) ft_printf_bonus.c
MOBJ=$(MFILES:%.c=$(SRC)/%.o)
BOBJ=$(BFILES:%.c=$(SRC)/%.o)


all: $(NAME)

$(NAME): $(MOBJ)
	ar rsc $(NAME) $(MOBJ)

bonus: $(BOBJ)
	ar rsc $(NAME) $(BOBJ)

$(SRC)/%.o : $(SRC)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean:
	rm -f $(MOBJ)
	rm -f $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

