/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_untils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:10:45 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/18 20:31:36 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_u(unsigned int nb, int i)
{
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_putnum_u(int i, unsigned int n, char *str)
{
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i + 1);
	i = 0;
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	i = ft_size_u(n, i);
	str = malloc(i + 2);
	if (str == 0)
		return (0);
	str[i + 1] = '\0';
	str = ft_putnum_u(i, n, str);
	return (str);
}

int	ft_size(int nb, int i)
{
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
