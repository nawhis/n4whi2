NAME = philo_bonus
SRCS = main.c print_message.c tf.c time_control.c arguments.c
OBJS = $(SRCS:.c=.o)
HEAD = philo_bonus.h
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
