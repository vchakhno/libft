# **************************************************************************** #
# 	Makefile based on clemedon's Makefile tutorial							   #
# **************************************************************************** #

NAME		:= libft.a

# **************************************************************************** #
# 	SOURCES																	   #
# **************************************************************************** #

include src/bounds/Makefile
include src/iterator/Makefile
include src/mem/Makefile
include src/str/Makefile
include src/char/Makefile
include src/printing/Makefile
include src/printf/Makefile

SRC_DIR		:= src
SRCS = \
	${addprefix bounds/,$(BOUNDS_SRCS)} \
	${addprefix iterator/,$(ITERATOR_SRCS)} \
	${addprefix mem/,$(MEM_SRCS)} \
	${addprefix str/,$(STR_SRCS)} \
	${addprefix char/,$(CHAR_SRCS)} \
	${addprefix printing/,$(PRINTING_SRCS)} \
	${addprefix printf/,$(PRINTF_SRCS)}
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

INCS		:= include

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

# **************************************************************************** #
# 	COMPILATION																   #
# **************************************************************************** #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
AR			= ar -rcs

# **************************************************************************** #
# 	UTILITIES																   #
# **************************************************************************** #

RM			:= rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP		= @mkdir -p $(@D)

# **************************************************************************** #
# 	RECIPIES :D																   #
# **************************************************************************** #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re