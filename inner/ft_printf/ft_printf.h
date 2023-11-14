/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:48:58 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/14 01:13:02 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_option
{
	int		flag[7]; // mn pl zr bl sh dt xX
	size_t	width;
	size_t	prec;
}	s_option;

typedef struct t_string
{
	char	*array;
	ssize_t	index;
	size_t	max;
} s_string;

int				ft_printf(const char * format, ...);
size_t			ft_strlen(char *str);
void			ft_realloc(s_string *str);
int				ft_check_realloc(s_string *str, size_t len);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t size, size_t count);
size_t			ft_check_size(size_t len, s_option *opt);
int				ft_putchar(char c, s_option *opt, s_string *str);
int				ft_putstr(char *s, s_option *opt, s_string *str);
void			ft_str_width(s_string *str, char *s, s_option *opt, size_t len);
void			ft_str_len(s_string *str, char *s, size_t len);
int				ft_putaddr(void *ad, s_option *opt, s_string *str);
int				ft_addrsize(unsigned long long addr);
void			ft_write_addr(s_string *str, unsigned long long addr, size_t len);
size_t			ft_numsize(long long num, s_option *opt);
char			*ft_write_num(int num, ssize_t size);
char			*ft_numtostr(int num, size_t *len, s_option *opt);
void			ft_fill_minus(char *nums, s_string *str, s_option *opt, size_t len);
void			ft_fill_no_minus(char *nums, s_string *str, s_option *opt, size_t len);
int				ft_putnbr(int num, s_option *opt, s_string *str);
char			*ft_write_unum(unsigned int num, ssize_t size);
char			*ft_unumtostr(unsigned int num, size_t *len, s_option *opt);
int				ft_putunbr(unsigned int num, s_option *opt, s_string *str);
size_t			ft_hexsize(unsigned int num);
char			*ft_write_hex(s_option *opt, unsigned int num, ssize_t size, char *xX);
char			*ft_hextostr(unsigned int num, size_t *len, s_option *opt);
int				ft_puthex(unsigned int num, s_option *opt, s_string *str, char xX);
char			*ft_parsing_fs(char *format, va_list *args, s_string *str, ssize_t *ret);
char			*ft_check_flag(char *format, s_option *opt);
ssize_t			ft_fs(char *format, va_list *args, s_string *str, s_option *opt);
struct t_string	*ft_init_str(void);

#endif