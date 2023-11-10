/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:48:58 by sihkang           #+#    #+#             */
/*   Updated: 2023/11/10 17:48:31 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef struct t_option
{
	int		flag[7]; // mn pl zr bl sh dt xX
	size_t	width;
	size_t	prec;
}	s_option;

typedef struct t_string
{
	char	*array;
	size_t	index;
	size_t	max;
} s_string;

int		ft_printf(const char * format, ...);



#endif