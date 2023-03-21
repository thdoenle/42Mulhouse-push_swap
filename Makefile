SRCS	= main.c lst.c stack.c instructions.c index_stack_values.c sort.c \
	exec_write.c simulate.c general_sort.c general_sort_utils.c \
	general_sort_best.c
OBJS	= $(SRCS:%.c=%.o)
HEADER	= push_swap.h
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
RM		= rm -rf
NAME	= push_swap

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME) bonus

bonus: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug
