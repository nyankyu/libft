SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re

all: libft.a

libft.a: $(OBJS)
	ar r libft.a  $(OBJS)

$(OBJS): $(SRCS) libft.h
	gcc -c -Wall -Werror -Wextra $(SRCS) -I.

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

