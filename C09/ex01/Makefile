CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
LIB = ranlib

SRC_DIR = srcs
INC_DIR = includes

SRCS = ${SRC_DIR}/ft_putchar.c ${SRC_DIR}/ft_swap.c ${SRC_DIR}/ft_putstr.c ${SRC_DIR}/ft_strlen.c ${SRC_DIR}/ft_strcmp.c
INCS = ${INC_DIR}/ft_header.h

OBJS = ${SRCS:.c=.o}

NAME = libft.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS}
	${AR} $(NAME) $(OBJS)
	${LIB} $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ${INC_DIR}/ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all