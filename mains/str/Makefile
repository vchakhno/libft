SRCS = str.c
BINS = ${SRCS:.c=.out}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
PROJECT_DIR = ../..
LIBS = $(PROJECT_DIR)/libft.a
INCLUDES = $(PROJECT_DIR)/include

.c.out:
	$(CC) $(CFLAGS) ${addprefix -I,$(INCLUDES)} $< $(LIBS) -o $@

all: $(BINS)

clean:
	rm -rf $(BINS)

fclean: clean

re:	fclean all