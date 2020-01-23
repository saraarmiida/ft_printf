/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:01:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/22 18:16:14 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_pow(int num, int power)
{
	long long	res;
	int			i;
	
	i = 1;
	res = num;
	while (i++ < power)
		res = res * num;
	return (res);
}

char	*ft_ftoa(long double n, int precision)
{
	long long	inum;
	long double	n2;
	char		*str1;
	char		*str2;
	int			i;
	char		*temp;

	n2 = (n < 0 ? -n : n);
	inum = (long long)n2;
	str1 = ft_itoa(inum);
	i = 0;
	n2 = n2 - inum;
	if (!(str2 = (char *)malloc(sizeof(char) * precision + 1)))
		return (NULL);
	while (i < precision)
	{
		inum = (long long)(n2 * 10);
		str2[i] = inum + '0';
		n2 = n2 * 10 - inum;
		i++;
	}
	str2[i] = '\0';
	inum = (long long)(n2 * 10);
	if (inum >= 5)
		str2[i - 1] += 1;
	if (precision != 0)
	{
		temp = ft_strjoin(str1, ".");
		free(str1);
		str1 = temp;
	}
	if (n < 0)
	{
		temp = ft_strjoin("-", str1);
		free(str1);
		str1 = temp;
	}
	temp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (temp);
}

void	c_double(t_menu *menu, va_list ap, char **str)
{
	int			n;
	char		*s;
	long double	num;
	char		c;
	char		*temp;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	if (menu->length)
		num = (long double)va_arg(ap, long double);
	else
		num = (long double)va_arg(ap, double);
	menu->precision = (menu->precision == -1 ? 6 : menu->precision);
	s = ft_ftoa(num, menu->precision);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		if (num < 0)
		{
			n = menu->precision - ft_strlen(s) + 2;
			temp = ft_memset(ft_strnew(n), '0', n);
			temp[0] = '-';
			s = ft_strjoin(temp, s + 1);
			free(temp);
		}
		else
		{
			n = menu->precision - ft_strlen(s);
			temp = ft_memset(ft_strnew(n), '0', n);
			s = ft_strjoin(temp, s);
			free(temp);
		}
	}
	if ((menu->plus || menu->space) && num > 0)
	{
		temp = ft_memset(ft_strnew(1), (menu->plus == 1 ? '+' : ' '), 1);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->width && menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			*str = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			*str = ft_strjoin(s, temp);
		free(temp);
	}
	else
		*str = ft_strdup(s);
	free(s);
}
