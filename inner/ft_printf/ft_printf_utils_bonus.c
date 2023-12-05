/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:10:59 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 20:52:56 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_realloc(t_string *str)
{
	char	*newstr;
	size_t	len;
	ssize_t	index;

	index = 0;
	len = (str->max) * 2;
	newstr = (char *)malloc(sizeof(char) * (len));
	if (newstr)
	{
		while (index < str->index)
		{
			newstr[index] = str->array[index];
			index++;
		}
		newstr[index] = 0;
	}
	str->max = len;
	free(str->array);
	str->array = newstr;
}

int	ft_check_realloc(t_string *str, size_t len)
{
	while (str->max <= str->index + len)
	{
		ft_realloc(str);
		if (!str->array)
			return (0);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
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

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
