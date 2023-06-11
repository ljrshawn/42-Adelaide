CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

SRCS = ${SRC_DIR}main.c ${SRC_DIR}readmap.c ${SRC_DIR}solve.c

NAME = bsq

.PHONY: all fclean re

all:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

fclean:
	rm -f ${NAME}

re: fclean all