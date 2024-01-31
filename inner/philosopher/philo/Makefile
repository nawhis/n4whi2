NAME = philo
SRCS = main.c arguments.c monitoring.c print_message.c tf.c thread_control.c time_control.c
OBJS = $(SRCS:.c=.o)
HEAD = philo.h
CC = cc 
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
