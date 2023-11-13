/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:55 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/13 21:19:56 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, s_option *opt, s_string *str)
{
	size_t	len;

	if (s == 0)
		s = "(null)";
	len = ft_strlen(s);
	if (opt->flag[2] && opt->flag[0])
		opt->flag[2] = 0;
	if (opt->flag[5] && opt->prec < len)
		len = opt->prec;
	if (opt->width > len)
	{
		if (!ft_check_realloc(str, opt->width))
			return (0);
		ft_str_width(str, s, opt, len);
	}
	else
	{
		if (!ft_check_realloc(str, len))
			return (0);
		ft_str_len(str, s, len);
	}
	return (1);
}

void	ft_str_width(s_string *str, char *s, s_option *opt, size_t len)
{
	size_t	idx;

	idx = 0;
	opt->width -= len;
	if (opt->flag[0])
	{
		while (idx < len)
			str->array[str->index++] = s[idx++];
		while (opt->width--)
			str->array[str->index++] = ' ';
	}
	else
	{
		while (opt->width--)
			str->array[str->index++] = ' ';
		while (idx < len)
			str->array[str->index++] = s[idx++];
	}
}

void	ft_str_len(s_string *str, char *s, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		str->array[str->index++] = *s++;
		idx++;
	}
}
