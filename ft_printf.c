/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:49:35 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 01:03:50 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_arg(char format, va_list ap)
{
	if (format == 'c' || format == '%')
		return (write_c(format, ap));
	if (format == 'd' || format == 'i')
		return (write_d_i(ap));
	if (format == 'u')
		return (write_u(ap));
	if (format == 'p')
		return (write_pointer(ap));
	if (format == 'x' || format == 'X')
		return (write_hex(format, ap));
	return (write_str(ap));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

int	is_specifier(const char *format)
{
	return (*format == '%' && ft_strchr("diucxXps%", *(format + 1)));
}

int	ft_printf(const char *format, ...)
{
	size_t	total_len;
	va_list	ap;
	int		current_len;

	total_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (is_specifier(format))
		{
			current_len = write_arg(*++format, ap);
			if (current_len == -1)
				return (-1);
			total_len += current_len;
			format++;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			total_len++;
		}
	}
	return (total_len);
}
