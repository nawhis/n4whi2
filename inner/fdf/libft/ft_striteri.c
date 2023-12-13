/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:52:54 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/12 14:45:34 by sihkang          ###   ########seoul.kr  */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s == 0 || f == 0)
		return ;
	index = 0;
	while (index < ft_strlen(s))
	{
		(*f)(index, &s[index]);
		index++;
	}
}
