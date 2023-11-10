/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:07:05 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/16 16:00:32 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char *dst, char const *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (s1 == 0 || s2 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (0);
	ft_copy(str, s1);
	ft_copy(&str[ft_strlen(s1)], s2);
	str[size - 1] = '\0';
	return (str);
}

static void	ft_copy(char *dst, char const *src)
{
	size_t	index;

	index = 0;
	while (*src)
	{
		dst[index++] = *src++;
	}
}
