NAME = pipex
NAME_B = pipex_bonus


LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GETNEXTLINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_DIR = src/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SRCS = 		$(SRC_DIR)pipex.c \
			$(SRC_DIR)processes.c \
			$(SRC_DIR)child_utils.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)error.c \
			$(SRC_DIR)here_doc.c \

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GETNEXTLINE) $(PRINTF) -o $(NAME)

$(NAME_B): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GETNEXTLINE) $(PRINTF) -o $(NAME_B)

all: $(NAME)

bonus: $(NAME_B)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

re_bonus: fclean bonus

.PHONY:	all clean fclean re
