/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:17:48 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/18 20:23:21 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list ap)
{
	char	n;

	n = va_arg(ap, int);
	write(1, &n, 1);
	return (1);
}

int	ft_print_s(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		i = ft_printf("(null)");
	else if (str[0] == 0)
		return (-1);
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_print_d(va_list ap)
{
	int		i;
	char	*num;

	i = 0;
	num = ft_itoa(va_arg(ap, int));
	while (num[i])
	{
		write (1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}

int	ft_print_u(va_list ap)
{
	int		i;
	char	*num;

	i = 0;
	num = ft_itoa_u(va_arg(ap, unsigned int));
	while (num[i])
	{
		write (1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}

int	ft_print_x(va_list ap, char	*p)
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
	i = ft_count(num);
	if (num == 0)
		f = 1;
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
