/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:47 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/19 14:12:43 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	size_t	size;

	index = 1;
	size = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)(&s[size]));
	while (index <= size)
	{
		if ((unsigned char)s[size - index] == (unsigned char)c)
			return ((char *)(&s[size - index]));
		index++;
	}
	return (0);
}
