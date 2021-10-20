/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:13:07 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/19 12:59:02 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_bx(va_list ap, char *p)
{
	unsigned int		i;
	unsigned int		k;
	unsigned int		num;
	int					f;
	char				*arr;

	arr = (NULL);
	f = 0;
	num = va_arg(ap, unsigned int);
	k = 0;
	if (num == 0)
		f = 1;
	i = ft_count(num);
	arr = ft_alloc(arr, i);
	arr = ft_st(num, arr, p);
	k = ft_k(num, arr, p);
	if (f == 1)
		arr[k++] = '0';
	arr[k] = '\0';
	ft_revprint(arr);
	free(arr);
	return (k);
}

int	ft_print_p(va_list ap)
{
	int	i;

	i = 0;
	i = i + (ft_printf_format('0'));
	i = i + ft_printf_format('x');
	i = i + ft_frintf_hexadecimal_p(va_arg(ap, unsigned long long int), i);
	return (i);
}

int	ft_parse_percent(const char fmt, va_list ap)
{
	int		len;
	char	*forx;
	char	*forbx;

	forx = "0123456789abcdef";
	forbx = "0123456789ABCDEF";
	len = 0;
	if (fmt == 'c')
		len = ft_print_c(ap);
	else if (fmt == 's')
		len = ft_print_s(ap);
	else if (fmt == 'd' || fmt == 'i')
		len = ft_print_d(ap);
	else if (fmt == 'u')
		len = ft_print_u(ap);
	else if (fmt == '%')
		len = ft_printf_format('%');
	else if (fmt == 'x')
		len = ft_print_x(ap, forx);
	else if (fmt == 'X')
		len = ft_print_bx(ap, forbx);
	else if (fmt == 'p')
		len = ft_print_p(ap);
	return (len);
}

int	ft_percent(const char *fmt, va_list ap)
{
	int	i;
	int	len;
	int	f;

	len = 0;
	i = 0;
	while (fmt[i])
	{
		f = 0;
		if (fmt[i] == '%' && fmt[i + 1])
			f = ft_parse_percent(fmt[i + 1], ap);
		else
			len += ft_printf_format(fmt[i]);
		if (f)
			i++;
		if (f == -1)
			f = 0;
		i++;
		len += f;
	}
	return (len);
}

int	ft_printf(const	char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	len = ft_percent(fmt, ap);
	va_end(ap);
	return (len);
}
