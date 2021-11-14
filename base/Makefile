# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:35:02 by oshelba           #+#    #+#              #
#    Updated: 2021/11/14 22:55:11 by oshelba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
processor/ft_pr_width.c \
processor/ft_processor_char.c \
processor/ft_processor_hex.c \
processor/ft_processor_int.c \
processor/ft_processor_percent.c \
processor/ft_processor_pointer.c \
processor/ft_processor_string.c \
processor/ft_processor_unit.c \
processor/ft_putchar.c \
processor/ft_putstrprec.c \
processor/ft_ull_base.c \
processor/processor.c \
processor/putstring.c \
parser/flags.c \
parser/parse_flag.c \
parser/parse_input.c \

HEADER = ft_printf.h

OBJS = ${SRCS:%.c=%.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

.PHONY : all clean fclean re

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	ar -rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f {NAME}

re : fclean all