/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:58:15 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:43:44 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	index;

	index = 0;
	if (s == 0 || f == 0)
		return (0);
	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (index < size)
	{
		str[index] = (*f)(index, s[index]);
		index++;
	}
	str[index] = 0;
	return (str);
}
