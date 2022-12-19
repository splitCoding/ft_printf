/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_diucs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:35:04 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 00:48:19 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_d_i(va_list ap)
{
	char	*itoa;
	int		num;

	num = va_arg(ap, int);
	itoa = ft_itoa(num);
	if (!itoa)
		return (-1);
	if (write(1, itoa, get_num_len_by(num, 10)) == -1)
	{
		free(itoa);
		return (-1);
	}
	free(itoa);
	return (get_num_len_by(num, 10));
}

int	write_u(va_list ap)
{
	int				num;
	char			*itoa;

	num = va_arg(ap, int);
	itoa = ft_uitoa((unsigned int)num);
	if (!itoa)
		return (-1);
	if (write(1, itoa, get_u_num_len_by(num, 10)) == -1)
	{
		free(itoa);
		return (-1);
	}
	free(itoa);
	return (get_u_num_len_by(num, 10));
}

int	write_c(char format, va_list ap)
{
	char	c;

	if (format == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	c = va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	write_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(1, str, ft_strlen(str)) == -1)
		return (-1);
	return (ft_strlen(str));
}
