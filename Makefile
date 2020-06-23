SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
NAME=libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libft.a $?

.c.o:
	gcc -Wall -Werror -Wextra -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all
