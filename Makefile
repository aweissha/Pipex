NAME = Pipex

LIBFT = libft/libft.a
SRC_DIR = src/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SRCS = 		$(SRC_DIR)pipex.c \
			$(SRC_DIR)processes.c \
			$(SRC_DIR)child_utils.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)error.c \


OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
