# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:19:46 by yhliboch          #+#    #+#              #
#    Updated: 2019/02/08 16:56:40 by yhliboch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/check.c ./src/ft_printf.c ./src/d_printf.c \
	./src/u_printf.c ./src/ft_itoa_u.c ./src/o_printf.c\
		./src/ft_itoa_base.c ./src/ft_itoa_x.c ./src/x_printf.c \
		./src/scp_printf.c ./src/change.c ./src/f_printf.c \
		./src/ft_itoa_f.c ./src/round.c ./src/ft_lstnew.c \
		./src/ft_putstr.c ./src/ft_strdel.c	./src/ft_strjoin.c \
		./src/ft_strnew.c ./src/ft_atoi.c ./src/ft_isdigit.c \
		./src/ft_lstaddend.c ./src/ft_memalloc.c ./src/ft_strchr.c \
		./src/ft_strdup.c ./src/ft_strlen.c ./src/ft_memset.c \
		./src/ft_strncpy.c ./src/ft_putchar.c ./src/ft_strncmp.c \
		./src/ft_memmove.c ./src/ft_bzero.c \
		./src/ft_itoa.c ./src/ft_itoa_d.c ./src/p_printf.c


INCL = ./src/ft_printf.h

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO)

	@ar rc $(NAME) $(SRCO)

%.o: %.c
	@clang -I$(INCL) $(FLAG) -o $@ -c $<

clean:
		@rm -f $(SRCO)

fclean: clean
		@rm -f $(NAME)

re: fclean all
