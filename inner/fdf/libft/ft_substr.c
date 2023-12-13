/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:56:06 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:44:17 by sihkang          ###   ########seoul.kr  */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) <= start)
	{
		str = (char *)ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (0);
	while (index < len && start + index < ft_strlen(s))
	{
		if (!s[start + index])
			break ;
		str[index] = s[start + index];
		index++;
	}
	return (str);
}
