# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:35:02 by oshelba           #+#    #+#              #
#    Updated: 2021/11/19 23:50:46 by oshelba          ###   ########.fr        #
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
processor/flags.c \
processor/parse_input.c \
processor/ft_pitoa.c \

HEADER = processor/ft_printf.h

OBJS = ${SRCS:%.c=%.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

.PHONY : all clean fclean re

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	${MAKE} -C ./libft all
	ar -rcs ${NAME} libft/*.o ${OBJS}

bonus : 
	${MAKE} ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${MAKE} clean -C ./libft
	rm -f ${OBJS}

fclean : clean
	${MAKE} fclean -C ./libft
	rm -f {NAME}

re : fclean all