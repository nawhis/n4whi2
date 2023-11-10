NAME = libftprintf.a
SRCS = $(wildcard *.c) 
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all : $(NAME)
bonus : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

re : fclean all

.PHONY : all clean fclean re bonus