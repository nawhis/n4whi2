/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:49:17 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 20:53:03 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_option *opt, t_string *str)
{
	size_t	len;

	len = 1;
	if (opt->width > 1)
		len = opt->width;
	if (!ft_check_realloc(str, len))
		return (0);
	if (opt->width > 1)
	{
		if (opt->flag[0])
		{
			str->array[str->index++] = c;
			while (--(opt->width))
				str->array[str->index++] = ' ';
		}
		else
		{
			while (--(opt->width))
				str->array[str->index++] = ' ';
			str->array[str->index++] = c;
		}
	}
	else
		str->array[str->index++] = c;
	return (1);
}

char	*ft_treat_num(char *format, t_option *opt)
{
	if (*format == '.')
	{
		opt->flag[5] = 1;
		while (*(++format) >= '0' && *format <= '9')
			opt->prec = opt->prec * 10 + *format - '0';
	}
	else
	{
		while (*format >= '0' && *format <= '9')
			opt->width = opt->width * 10 + *format++ - '0';
	}
	format--;
	return (format);
}
