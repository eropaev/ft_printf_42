NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = includes/printf.h 

CFILES = src/*.c 
OFILES = *.o 

all: $(NAME)

$(NAME):
		gcc $(CFLAGS) -I $(HEADER) -c$(CFILES)
		ar rc $(NAME) $(OFILES)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OFILES)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all