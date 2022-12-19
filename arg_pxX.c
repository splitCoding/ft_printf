/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:49:50 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 01:02:32 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_ulnum_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itop(unsigned long address)
{
	int				len;
	char			*arr;

	len = get_hex_ulnum_len(address) + 2;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[len--] = '\0';
	arr[0] = '0';
	arr[1] = 'x';
	arr[2] = '0';
	while (address)
	{
		arr[len--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	return (arr);
}

int	write_pointer(va_list ap)
{
	unsigned long	l_num;
	char			*arr;
	int				current_len;

	l_num = va_arg(ap, unsigned long);
	arr = ft_itop(l_num);
	if (!arr)
		return (-1);
	current_len = write(1, arr, get_hex_ulnum_len(l_num) + 2);
	free(arr);
	if (current_len == -1)
		return (-1);
	return (current_len);
}

int	get_hex_unum_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	write_hex(char format, va_list ap)
{
	unsigned long	num;
	char			*arr;
	int				current_len;

	num = va_arg(ap, unsigned int);
	if (format == 'x')
		arr = ft_itoa_hex_lower(num);
	else
		arr = ft_itoa_hex_upper(num);
	if (!arr)
		return (-1);
	current_len = write(1, arr, get_hex_unum_len(num));
	free(arr);
	if (current_len == -1)
		return (-1);
	return (current_len);
}
