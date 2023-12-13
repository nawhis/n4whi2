/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:42:13 by sihkang           #+#    #+#             */
/*   Updated: 2023/10/18 20:01:50 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_words(char const *s, char c);
static size_t	ft_n_char(char const *s, char c);
static void		ft_free_arr(char **words, size_t num);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	num;

	num = 0;
	if (s == 0)
		return (0);
	words = (char **)ft_calloc((ft_n_words(s, c) + 1), sizeof(char *));
	if (!words)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		words[num] = (char *)ft_calloc((ft_n_char(s, c) + 1), sizeof(char));
		if (!words[num])
		{
			ft_free_arr(words, num);
			return (0);
		}
		ft_memcpy(words[num++], s, ft_n_char(s, c));
		s += ft_n_char(s, c);
	}
	return (words);
}

static void	ft_free_arr(char **words, size_t num)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		free(words[index++]);
	}
	free(words);
}

static size_t	ft_n_words(char const *s, char c)
{
	size_t	index;
	size_t	len;
	size_t	num_words;

	len = 0;
	num_words = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c)
			len++;
		else if (s[index] == c && len)
		{
			num_words++;
			len = 0;
		}
		index++;
	}
	if (len)
		num_words++;
	return (num_words);
}

static size_t	ft_n_char(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
			len++;
		else
			return (len);
		s++;
	}
	return (len);
}
