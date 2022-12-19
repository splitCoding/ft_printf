/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pxX_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:58:32 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 01:03:08 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hex_lower(unsigned int n)
{
	int		len;
	int		idx;
	char	*arr;

	len = get_hex_unum_len(n);
	idx = get_hex_unum_len(n);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr == NULL)
		return (0);
	arr[idx--] = '\0';
	while (idx >= 0)
	{
		arr[idx--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	if (arr[0] == '0' && len > 1)
		arr[0] = '-';
	return (arr);
}

char	*ft_itoa_hex_upper(unsigned int n)
{
	int		len;
	int		idx;
	char	*arr;

	len = get_hex_unum_len(n);
	idx = get_hex_unum_len(n);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr == NULL)
		return (0);
	arr[idx--] = '\0';
	while (idx >= 0)
	{
		arr[idx--] = "0123456789ABCDEF"[get_abs(n % 16)];
		n /= 16;
	}
	if (arr[0] == '0' && len > 1)
		arr[0] = '-';
	return (arr);
}
