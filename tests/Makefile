include first_part/Makefile
include second_part/Makefile

SRCS = \
	$(addprefix first_part/,${SRCS_FIRST_PART}) \
	$(addprefix second_part/,${SRCS_SECOND_PART})
BINS = ${SRCS:.c=.out}
INCS = ../include
NAME = ../libft.a
CC 	= gcc
RM 	= rm -f
CFLAGS = -Wall -Wextra -Werror

all: tests

tests: ${BINS}

.c.out: ${NAME}
	${CC} ${CFLAGS} $< ${NAME} -o ${<:.c=.out} -I ${INCS}

clean:
	${RM} ${BINS}

echo:
	echo ${BINS}

re: clean all
