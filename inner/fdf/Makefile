NAME = fdf
SRCS_MAN = eqs_arrays.c hooking.c makemap.c pixel_dotting.c projection.c rotate.c setting.c translate.c zoom.c fdf.c
OBJS_MAN = $(SRCS_MAN:.c=.o)
SRCS_BON = fdf_bonus.c eqs_arrays_bonus.c hooking_bonus.c makemap_bonus.c pixel_dotting_bonus.c projection_bonus.c rotate_bonus.c setting_bonus.c translate_bonus.c zoom_bonus.c
OBJS_BON = $(SRCS_BON:.c=.o)
HEADER_MAN = fdf.h
HEADER_BON = fdf_bonus.h
TMP_FILE = MAN BON
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

ifdef BONUS
	SRCS = $(SRCS_BON) 
	HEADER = $(HEADER_BON)
	OBJS = $(OBJS_BON)
	EXE = BON
else
	SRCS = $(SRCS_MAN) 
	HEADER = $(HEADER_MAN)
	OBJS = $(OBJS_MAN)
	EXE = MAN
endif

all : $(NAME) 

bonus : 
	make BONUS=1

$(NAME) : $(OBJS) $(EXE)
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./libft
	$(MAKE) -C ./get_next_line
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./ft_printf/libftprintf.a ./libft/libft.a ./get_next_line/gnl.a
	rm -f $(TMP_FILE)
	touch $(EXE)

$(EXE) : 
	touch $(EXE)



%.o : %.c
	$(CC) -c $<

clean :
	$(MAKE) -C ./ft_printf clean
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./get_next_line clean
	rm -f $(OBJS_BON) $(OBJS_MAN) $(GNL_OBJS) $(TMP_FILE)

fclean : clean
	$(MAKE) -C ./ft_printf fclean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./get_next_line fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus