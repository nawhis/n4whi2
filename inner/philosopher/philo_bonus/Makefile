NAME = philo_bonus
SRCS = main_bonus.c print_message_bonus.c tf_bonus.c time_control_bonus.c arguments_bonus.c clean_bonus.c value_setting_bonus.c
OBJS = $(SRCS:.c=.o)
HEAD = philo_bonus.h
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g 

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
