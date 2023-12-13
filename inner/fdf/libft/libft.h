/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:24:13 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/13 17:14:34 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_libft
{
	void				*content;
	struct s_list_libft	*next;
}				t_list_libft;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
t_list_libft	*ft_lstnew(void *content);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memmove(void *dst, void *src, size_t len);
t_list_libft	*ft_lstnew(void *content);
t_list_libft	*ft_lstlast(t_list_libft *lst);
void	ft_lstdelone(t_list_libft *lst, void (*del)(void *));
void	ft_lstclear(t_list_libft **lst, void (*del)(void *));
void	ft_lstadd_back(t_list_libft **lst, t_list_libft *new);
void	ft_lstadd_front(t_list_libft **lst, t_list_libft *new);
int		ft_lstsize(t_list_libft *lst);
void	ft_lstiter(t_list_libft *lst, void (*f)(void *));
t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *), void (*del)(void *));

#endif