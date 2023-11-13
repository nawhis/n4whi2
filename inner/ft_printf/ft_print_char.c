/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:49:17 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/11 13:08:58 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, s_option *opt, s_string *str)
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
