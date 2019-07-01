# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ieropaie <ieropaie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 17:29:40 by ieropaie          #+#    #+#              #
#    Updated: 2019/06/30 17:45:14 by ieropaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_printf.c		po_tipu.c		parsing.c		melkay_s.c \
		   bolshoy_s.c		melkay_p.c		melkay_d.c		bolshoy_d.c \
		   melkay_i.c		melkay_o.c		bolshoy_o.c 	melkay_c.c\
		   melkay_u.c		bolshoy_u.c		melkay_x.c		bolshoy_x.c \
		   bolshoy_c.c		modul.c			dop_probel.c	unsigned.c \
		   dop_func.c 		dop_func01.c	po_tipu.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
