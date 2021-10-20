/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:16:22 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/19 12:56:40 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int num)
{
	unsigned int	k;
	unsigned int	i;

	i = 0;
	k = num;
	while (k != 0)
	{
		k = k / 16;
		i++;
	}
	return (i);
}

char	*ft_alloc(char *arr, unsigned int i)
{
	arr = malloc(sizeof(char) * i + 1);
	if (!arr)
		return (0);
	return (arr);
}

char	*ft_st(unsigned int num, char *arr, char *p)
{
	unsigned int	i;
	unsigned int	k;

	k = 0;
	i = 0;
	while (num != 0)
	{
		i = num;
		i = i % 16;
		num = num / 16;
		arr[k] = p[i];
		k++;
	}
	return (arr);
}

int	ft_k(unsigned int num, char *arr, char *p)
{
	unsigned int	i;
	unsigned int	k;

	k = 0;
	i = 0;
	while (num != 0)
	{
		i = num;
		i = i % 16;
		num = num / 16;
		arr[k] = p[i];
		k++;
	}
	return (k);
}

int	ft_frintf_hexadecimal_p(unsigned long long int x, int n)
{
	char	*a;

	a = "0123456789abcdef";
	n = 0;
	if (x >= 16)
		n = ft_frintf_hexadecimal_p((x / 16), n);
	else
	{
		if (x < 0)
		{
			x = x * -1;
		}	
		n = n + ft_printf_format(a[x]);
		return (n);
	}
	x = x % 16;
	if (x < 0)
		x = x * -1;
	n = n + ft_printf_format(a[x]);
	return (n);
}
