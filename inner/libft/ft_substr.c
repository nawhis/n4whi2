/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:56:06 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/19 21:41:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
