/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:14:46 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/19 12:50:27 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_revprint(char *str)
{
	char	buff;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[n])
		n++;
	while (n - 1 > i)
	{
		buff = str[i];
		str[i] = str[n - 1];
		str[n - 1] = buff;
		n--;
		i++;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf_format(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_putnum(int i, int f, int n, char *str)
{
	while (i >= f)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		f;

	f = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		f = 1;
		i++;
	}
	i = ft_size(n, i);
	str = malloc(i + 2);
	if (str == 0)
		return (0);
	str[i + 1] = '\0';
	str = ft_putnum(i, f, n, str);
	if (f == 1)
		str[0] = '-';
	return (str);
}
