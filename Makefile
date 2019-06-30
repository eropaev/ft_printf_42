# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 17:29:40 by ieropaie          #+#    #+#              #
#    Updated: 2019/06/30 02:40:06 by ieropaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libtftprintf.a
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -Rf
LIB		=	libtft/libft.a
LIBSRC	=	libtft/
HEADER	=	libftprintf.h
LHEADER =	./libtft/libft.
OBJDIR	=	./obj/
LOBJDIR	=	./libtft/
SRCDIR	=	./src/
LSRCDIR =	./libtft/


SRC		=  ft_printf.c		po_tipu.c		parsing.c		melkay_s.c \
		   bolshoy_s.c		melkay_p.c		melkay_d.c		bolshoy_d.c \
		   melkay_i.c		melkay_o.c		bolshoy_o.c 	melkay_c.c\
		   melkay_u.c		bolshoy_u.c		melkay_x.c		bolshoy_x.c \
		   upper_c.c		modul.c			dop_probel.c	unsigned.c \
		   dop_func.c 		dop_func01.c	po_tipu.c

LSRC	= *.c

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
