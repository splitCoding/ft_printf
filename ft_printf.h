/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:49:39 by sanghyep          #+#    #+#             */
/*   Updated: 2022/12/20 01:10:06 by sanghyep         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		is_specifier(const char *format);
char	*ft_strchr(const char *s, int c);
int		write_arg(char format, va_list ap);
int		write_c(char format, va_list ap);
int		write_u(va_list ap);
char	*ft_uitoa(unsigned int n);
int		get_u_num_len_by(unsigned int n, int by);
int		write_d_i(va_list ap);
char	*ft_itoa(int n);
int		get_num_len_by(int n, int by);
int		get_abs(int n);
int		write_str(va_list ap);
size_t	ft_strlen(const char *s);
int		write_pointer(va_list ap);
char	*ft_itop(unsigned long address);
int		get_hex_ulnum_len(unsigned long n);
int		write_hex(char format, va_list ap);
char	*ft_itoa_hex_lower(unsigned int n);
char	*ft_itoa_hex_upper(unsigned int n);
int		get_hex_unum_len(unsigned int n);

#endif