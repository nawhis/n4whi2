NAME = gnl.a
GNLS = get_next_line.c get_next_line_utils.c
GNL_OBJS = get_next_line.o get_next_line_utils.o
HEADER_MAN = get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME) 

$(NAME) : $(GNL_OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) -c $<

clean :
	rm -f $(GNL_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus