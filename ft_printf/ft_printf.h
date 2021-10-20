/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:18:10 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/19 12:54:05 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const	char *fmt, ...);
int		ft_size_u(unsigned int nb, int i);
int		ft_size(int nb, int i);
int		ft_printf_format(char c);
int		ft_print_c(va_list ap);
int		ft_print_s(va_list ap);
int		ft_print_d(va_list ap);
int		ft_print_u(va_list ap);
int		ft_print_x(va_list ap, char *p);
int		ft_print_bx(va_list ap, char *p);
int		ft_print_p(va_list ap);
int		ft_parse_percent(const char fmt, va_list ap);
int		ft_percent(const char *fmt, va_list ap);
int		ft_count(unsigned int num);
int		ft_k(unsigned int num, char *arr, char *p);
int		ft_frintf_hexadecimal_p(unsigned long long int x, int n);

char	*ft_st(unsigned int num, char *arr, char *p);
char	*ft_alloc(char *arr, unsigned int i);
char	*ft_putnum(int i, int f, int n, char *str);
char	*ft_putnum_u(int i, unsigned int n, char *str);
char	*ft_strdup(const char *s1);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);

void	ft_revprint(char *str);

#endif