/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:12:34 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/04 16:38:43 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_find_node(t_list *head, int fd)
{
	t_list	*node;

	node = head;
	while (node->next)
	{
		if ((int)node->next->buf_info[0] == fd)
			return (node->next);
		node = node->next;
	}
	node->next = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!node->next)
		return (0);
	node->next->buf = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	node->next->buf_info = (long long *)ft_calloc(sizeof(long long), 3);
	if (!(node->next->buf_info) || !(node->next->buf))
	{
		free(node->next->buf);
		free(node->next->buf_info);
		free(node->next);
		node->next = 0;
		return (0);
	}
	node->next->buf_info[0] = fd;
	return (node->next);
}

char	*ft_find_next_line(t_list *head, int fd)
{
	char	*str;
	size_t	str_index;
	size_t	str_max;
	t_list	*node;

	str_index = 0;
	str_max = BUFFER_SIZE;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	node = (ft_find_node(head, fd));
	if (!node)
	{
		free(str);
		return (0);
	}
	str = ft_make_str(node, str, str_index, str_max);
	if (str == 0 || str[0] == '\0' || node->buf_info[2] == -1)
	{
		free(str);
		str = 0;
	}
	return (str);
}

char	*ft_make_str(t_list *node, char *str, size_t str_index, size_t str_max)
{
	while (1)
	{
		if (node->buf_info[1] == node->buf_info[2])
		{
			node->buf_info[1] = 0;
			node->buf_info[2] = read(node->buf_info[0], node->buf, BUFFER_SIZE);
			if (node->buf_info[2] <= 0)
				return (ft_realloc(str, str_index, &str_max, 1));
		}
		while (node->buf_info[1] < node->buf_info[2])
		{
			str[str_index] = node->buf[node->buf_info[1]++];
			if (str[str_index++] == '\n')
				return (ft_realloc(str, str_index, &str_max, 1));
			else if (str_index == str_max)
			{
				str = ft_realloc(str, str_index, &str_max, 0);
				if (!str)
					return (0);
			}
		}
		if (node->buf_info[2] < BUFFER_SIZE)
			return (ft_realloc(str, str_index, &str_max, 1));
	}
}

char	*ft_realloc(char *str, size_t str_index, size_t	*str_max, int option)
{
	char	*newstr;
	size_t	len;
	size_t	index;

	index = 0;
	if (option == 0)
		len = (str_index + BUFFER_SIZE) * 2;
	else
		len = str_index;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr)
	{
		while (index < str_index)
		{
			newstr[index] = str[index];
			index++;
		}
		newstr[index] = 0;
	}
	*str_max = len;
	free(str);
	str = 0;
	return (newstr);
}

void	*ft_calloc(size_t size, size_t count)
{
	void	*mem;
	size_t	index;

	index = 0;
	if ((size != 0 && (size_t)-1 / size < count))
		return (0);
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (index < count * size)
		((char *)mem)[index++] = 0;
	return (mem);
}
