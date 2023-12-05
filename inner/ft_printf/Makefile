NAME = libftprintf.a
SRCS_MAN = ft_printf.c ft_printf_utils.c ft_print_char.c \
			ft_print_str.c ft_print_nums.c ft_print_unums.c \
			ft_print_addr.c ft_print_hex.c
SRCS_BON = ft_printf_bonus.c ft_printf_utils_bonus.c \
			ft_print_char_bonus.c ft_print_str_bonus.c \
			ft_print_nums_bonus.c ft_print_unums_bonus.c \
			ft_print_addr_bonus.c ft_print_hex_bonus.c 
OBJS_MAN = $(SRCS_MAN:.c=.o)
OBJS_BON = $(SRCS_BON:.c=.o)
HEADER_MAN = ft_printf.h
HEADER_BON = ft_printf_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

ifdef BONUS
	OBJ_FILE = $(OBJS_BON)
	HEADER = $(HEADER_BON)
else
	OBJ_FILE = $(OBJS_MAN)
	HEADER = $(HEADER_MAN)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus :
	make BONUS=1

clean :
	rm -f $(OBJS_MAN)
	rm -f $(OBJS_BON)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
