NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS = $(SRCS:.c=.o)
SRCS_BON = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c 
OBJS_BON = $(SRCS_BON:.c=.o)
TMP_FILE = make_man make_bon
HEADER = libft.h
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

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