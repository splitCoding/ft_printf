/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_diuc%s_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:43:49 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 00:49:15 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_len_by(int n, int by)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= by;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		idx;
	char	*arr;

	len = get_num_len_by(n, 10);
	idx = get_num_len_by(n, 10);
	arr = (char *)malloc(sizeof(char) *(len + 1));
	if (!arr)
		return (NULL);
	arr[idx--] = '\0';
	while (idx >= 0)
	{
		arr[idx--] = '0' + get_abs(n % 10);
		n /= 10;
	}
	if (arr[0] == '0' && len > 1)
		arr[0] = '-';
	return (arr);
}

int	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_u_num_len_by(unsigned int n, int by)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= by;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	int		idx;
	char	*arr;

	len = get_u_num_len_by(n, 10);
	idx = get_u_num_len_by(n, 10);
	arr = (char *)malloc(sizeof(char) *(len + 1));
	if (!arr)
		return (NULL);
	arr[idx--] = '\0';
	while (idx >= 0)
	{
		arr[idx--] = '0' + get_abs(n % 10);
		n /= 10;
	}
	if (arr[0] == '0' && len > 1)
		arr[0] = '-';
	return (arr);
}
