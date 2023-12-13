/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:48:58 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/14 20:56:55 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_option
{
	int		flag[7];
	size_t	width;
	size_t	prec;
}	t_option;

typedef struct s_string
{
	char	*array;
	ssize_t	index;
	size_t	max;
}	t_string;

int				ft_printf(const char *format, ...);
size_t			ft_strlen(char *str);
void			ft_realloc(t_string *str);
int				ft_check_realloc(t_string *str, size_t len);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t size, size_t count);
size_t			ft_check_size(size_t len, t_option *opt);
char			*ft_treat_num(char *format, t_option *opt);
int				ft_putchar(char c, t_option *opt, t_string *str);
int				ft_putstr(char *s, t_option *opt, t_string *str);
void			ft_str_width(t_string *str, char *s, t_option *opt, size_t len);
void			ft_str_len(t_string *str, char *s, size_t len);
int				ft_putaddr(void *ad, t_option *opt, t_string *str);
size_t			ft_addrsize(unsigned long long addr);
void			ft_write_addr(t_string *str, unsigned long long addr, \
size_t len);
void			ft_width_bigger(t_string *str, t_option *opt, \
unsigned long long addr, size_t len);
size_t			ft_numsize(long long num, t_option *opt);
char			*ft_write_num(int num, ssize_t size);
char			*ft_numtostr(int num, size_t *len, t_option *opt);
void			ft_fill_minus(char *nums, t_string *str, t_option *opt, \
size_t len);
void			ft_fill_no_minus(char *nums, t_string *str, t_option *opt, \
size_t len);
int				ft_putnbr(int num, t_option *opt, t_string *str);
char			*ft_write_unum(unsigned int num, ssize_t size);
char			*ft_unumtostr(unsigned int num, size_t *len, t_option *opt);
int				ft_putunbr(unsigned int num, t_option *opt, t_string *str);
size_t			ft_hexsize(unsigned int num);
char			*ft_write_hex(t_option *opt, unsigned int num, ssize_t size, \
char *xX);
char			*ft_hextostr(unsigned int num, size_t *len, t_option *opt);
int				ft_puthex(unsigned int num, t_option *opt, t_string *str, \
	char xX);
char			*ft_parsing_fs(char *format, va_list *args, t_string *str, \
ssize_t *ret);
char			*ft_check_flag(char *format, t_option *opt);
ssize_t			ft_fs(char *format, va_list *args, t_string *str, \
t_option *opt);
struct s_string	*ft_init_str(void);

#endif