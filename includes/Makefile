NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = includes/printf.h

CFILES = src/ft_abs.c src/ft_atoi_baze.c src/ft_count.c src/ft_count1.c src/ft_itoia_bz.c src/ft_printf.c src/ft_putchar.c src/ft_putstr.c src/ft_strlen.c
OFILES = *.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I$(HEADER) -c $(CFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
