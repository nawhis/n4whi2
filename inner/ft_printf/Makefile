NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_print_char.c ft_print_str.c ft_print_nums.c ft_print_unums.c ft_print_addr.c ft_print_hex.c
OBJS = $(SRCS:.c=.o)
TMP_FILE = make_man make_bon
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

# ifdef WITH_BONUS
# 	OBJS = $(OBJS) $(OBJS_BONUS)
# else
# 	OBJS = $(OBJS)

all : $(NAME)
bonus : $(NAME) make_bon

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	touch make_man

make_bon : $(OBJS) $(OBJS_BON)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch make_man $@

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BON)
	rm -f $(TMP_FILE)

fclean : clean
	rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

re : fclean all

.PHONY : all clean fclean re bonus