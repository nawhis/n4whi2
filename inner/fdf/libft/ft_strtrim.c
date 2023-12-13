/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:31:07 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:44:11 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set);

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	size;
	size_t	start;

	index = 0;
	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	size = ft_strlen(s1);
	while (index < size && ft_isinset(s1[index], set))
		index++;
	while (index < size && ft_isinset(s1[size - 1], set))
		size--;
	size = size - index;
	return (ft_substr(s1, index, size));
}

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (c != *set)
			set++;
		else
			return (1);
	}
	return (0);
}
