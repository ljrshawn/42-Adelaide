CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

DIRSRC = srcs/

SRCS = ${DIRSRC}main.c

OBJS = ${SRCS:.c=.o}

NAME = ft_display_file

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${CFLAGS}

all:	${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re