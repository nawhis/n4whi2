/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 02:04:29 by sihwan            #+#    #+#             */
/*   Updated: 2023/11/14 21:08:11 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_string	*ft_init_str(void)
{
	t_string	*str;

	str = (t_string *)ft_calloc(sizeof(t_string), 1);
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
	t_string	*str;
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

char	*ft_parsing_fs(char *format, va_list *args, t_string *str, ssize_t *ret)
{
	t_option	*opt;

	if (*format == '%')
	{
		opt = (t_option *)ft_calloc(sizeof(t_option), 1);
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

char	*ft_check_flag(char *format, t_option *opt)
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
		else if (*format == '.' || (*format >= '0' && *format <= '9'))
			format = ft_treat_num(format, opt);
		else
			break ;
		format++;
	}
	return (format);
}

ssize_t	ft_fs(char *format, va_list *args, t_string *str, t_option *opt)
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
	else
		ret = 0;
	return (ret);
}
