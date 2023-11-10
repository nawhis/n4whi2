/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:27:28 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/04 16:28:19 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	long long		*buf_info;
	char			*buf;
	struct s_list	*next;
}			t_list;

char	*ft_find_next_line(t_list *node, int fd);
char	*ft_make_str(t_list *node, char *str, size_t str_index, size_t str_max);
t_list	*ft_find_node(t_list *head, int fd);
char	*get_next_line(int fd);
char	*ft_realloc(char *str, size_t str_index, size_t	*str_max, int option);
void	*ft_calloc(size_t size, size_t count);

#endif