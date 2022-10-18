include src/first_part/Makefile
include src/second_part/Makefile

SRCS = \
	$(addprefix src/first_part/, ${SRCS_FIRST_PART}) \
	$(addprefix src/second_part/, ${SRCS_SECOND_PART})
OBJS = ${SRCS:.c=.o}
BONUS_SRCS = \
	$(addprefix src/third_part/, ${SRCS_THIRD_PART})
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
INCS = include
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
CC 	= gcc
RM 	= rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	${LIBC} ${NAME} ${OBJS} ${BONUS_OBJS}
	${LIBR} ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all