/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 02:04:29 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 02:07:52 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_string	*ft_init_str(void)
{
	s_string	*str;

	str = (s_string *)ft_calloc(sizeof(s_string), 1);
	if (!str)
		return (0);
	str->max = 1024;
	str->array = (char *)ft_calloc(sizeof(char), str->max);
	if (!str->array)
	{
		free(str);
		return (0);
	}
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	s_string	*str;
	ssize_t		ret;

	str = ft_init_str();
	if (!str)
		return (-1);
	ret = 1;
	va_start(args, format);
	while (ret && *format != '\0')
	{
		format = ft_parsing_fs((char *)format, &args, str, &ret);
		if (ret == 0)
			str->index = -1;
	}
	va_end(args);
	ret = str->index;
	if (write(1, str->array, str->index) == -1)
		ret = -1;
	free(str->array);
	free(str);
	return (ret);
}

char	*ft_parsing_fs(char *format, va_list *args, s_string *str, ssize_t *ret)
{
	s_option	*opt;

	if (*format == '%')
	{
		opt = (s_option *)ft_calloc(sizeof(s_option), 1);
		if (!opt)
		{
			*ret = 0;
			return (format);
		}
		format = ft_check_flag(++format, opt);
		*ret = ft_fs(format, args, str, opt);
		if (ret)
			format++;
		free(opt);
	}
	else
	{
		if (ft_check_realloc(str, 1))
			str->array[str->index++] = *(format++);
		else
			return (0);
	}
	return (format);
}

char	*ft_check_flag(char *format, s_option *opt)
{
	while (!ft_strchr("cspdiuxX%", *format))
	{
		if (*format == '-')
			opt->flag[0] = 1;
		else if (*format == '+')
			opt->flag[1] = 1;
		else if (*format == '0')
			opt->flag[2] = 1;
		else if (*format == ' ')
			opt->flag[3] = 1;
		else if (*format == '#')
			opt->flag[4] = 1;
		else if (*format == '.')
		{
			opt->flag[5] = 1;
			while (*(++format) >= '0' && *format <= '9')
				opt->prec = opt->prec * 10 + *format - '0';
			format--;
		}
		else
		{
			while (*format >= '0' && *format <= '9')
				opt->width = opt->width * 10 + *format++ - '0';
			format--;
		}
		format++;
	}
	return (format);
}

ssize_t	ft_fs(char *format, va_list *args, s_string *str, s_option *opt)
{
	ssize_t	ret;

	ret = 1;
	if (*format == 'd' || *format == 'i')
		ret = ft_putnbr(va_arg(*args, int), opt, str);
	else if (*format == 'x')
		ret = ft_puthex(va_arg(*args, unsigned int), opt, str, 'x');
	else if (*format == 'X')
		ret = ft_puthex(va_arg(*args, unsigned int), opt, str, 'X');
	else if (*format == 's')
		ret = ft_putstr(va_arg(*args, char *), opt, str);
	else if (*format == 'c' )
		ret = ft_putchar(va_arg(*args, int), opt, str);
	else if (*format == 'u')
		ret = ft_putunbr(va_arg(*args, unsigned int), opt, str);
	else if (*format == 'p')
		ret = ft_putaddr(va_arg(*args, void *), opt, str);
	else if (*format == '%')
		ret = ft_putchar('%', opt, str);
	return (ret);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	printf("|%d|", printf("printf   :|%-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d,|\n",0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
// 	printf("|%d|", ft_printf("ft_printf:|%-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d,|\n",0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
// }
