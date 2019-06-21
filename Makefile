# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 17:29:40 by ieropaie          #+#    #+#              #
#    Updated: 2019/06/20 17:36:21 by ieropaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libtftprintf.a
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -Rf
LIB		=	libtft/libft.a
LIBSRC	=	libtft/
HEADER	=	includes/
LHEADER =	./libtft/
OBJDIR	=	./obj/
LOBJDIR	=	./libtft/
SRCDIR	=	./src/
LSRCDIR =	./libtft/


SRC		=  ft_printf.c		get_type.c		parser.c		lower_s.c \
		   upper_s.c		lower_p.c		lower_d.c		upper_d.c \
		   lower_i.c		lower_o.c		upper_o.c 		lower_c.c\
		   lower_u.c		upper_u.c		lower_x.c		upper_x.c \
		   upper_c.c		modulo.c		int_utils.c		str_utils.c \
		   tab_utils.c 		uint_utils.c	wstr_utils.c	undefined.c

LSRC	= ft_atoi.c			ft_itoa.c		ft_memmove.c	ft_putstr.c \
		  ft_strdel.c		ft_strlen.c		ft_strnew.c		ft_tolower.c \
		  ft_bzero.c		ft_memalloc.c	ft_memset.c		ft_putstr_fd.c \
		  ft_strdup.c		ft_strmap.c		ft_strnstr.c	ft_toupper.c \
		  ft_isalnum.c		ft_memccpy.c	ft_putchar.c	ft_strcat.c \
		  ft_strequ.c		ft_strmapi.c	ft_strrchr.c	ft_isalpha.c \
		  ft_memchr.c		ft_putchar_fd.c	ft_strchr.c		ft_striter.c \
		  ft_strncat.c		ft_strsplit.c	ft_isascii.c	ft_memcmp.c \
		  ft_putendl.c		ft_strclr.c		ft_striteri.c	ft_strncmp.c \
		  ft_strstr.c		ft_isdigit.c	ft_memcpy.c		ft_putendl_fd.c \
		  ft_strcmp.c		ft_strjoin.c	ft_strncpy.c	ft_strsub.c \
		  ft_isprint.c		ft_memdel.c		ft_putnbr.c		ft_strcpy.c \
		  ft_strlcat.c		ft_strnequ.c	ft_strtrim.c	ft_putnbr_fd.c \
		  ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c \
		  ft_lstiter.c		ft_lstmap.c		ft_strrev.c		ft_power.c \
		  ft_islower.c		ft_isupper.c	ft_isspace.c

SRCS	=	$(addprefix $(SRCDIR), $(SRC))
LSRCS	=	$(addprefix $(LSRCDIR), $(LSRC))
OBJS	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))
LOBJS 	=	$(addprefix $(LOBJDIR), $(LSRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJS) $(LOBJS)
	ar rc $(NAME) $(OBJS) $(LOBJS)
	ranlib $(NAME)

$(LIB):
	make -C $(LIBSRC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)libftprintf.h
	$(CC) -o $@ $(FLAG) -c $< -I $(HEADER)

$(LOBJDIR)%.o:$(LSRCDIR)%.c $(LHEADER)libft.h
	$(CC) -o $@ $(FLAG) -c $< -I $(LHEADER)

clean:
	$(RM) $(OBJS)
	make -C $(LIBSRC) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBSRC) fclean

re: fclean all
	make -C $(LIBSRC) re

.PHONY: clean fclean re
