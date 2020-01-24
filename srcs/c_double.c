/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:01:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/24 18:44:56 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	double_precision(t_menu *menu, char **s, long double num)
{
	int		n;
	char	*temp;
	char	*temp2;

	if (menu->precision != -1 && menu->precision > ft_strlen(*s))
	{
		if (num < 0)
		{
			n = menu->precision - ft_strlen(*s) + 2;
			temp = ft_memset(ft_strnew(n), '0', n);
			temp[0] = '-';
			temp2 = ft_strjoin(temp, *s + 1);
		}
		else
		{
			n = menu->precision - ft_strlen(*s);
			temp = ft_memset(ft_strnew(n), '0', n);
			temp2 = ft_strjoin(temp, *s);
		}
		free(temp);
		free(*s);
		*s = temp2;
	}
}

void	double_modifiers(t_menu *menu, char **s, long double num)
{
	char	*str;
	char	c;
	int		n;
	char	*str2;

	if ((menu->plus || menu->space) && num >= 0)
	{
		str = ft_memset(ft_strnew(1), (menu->plus == 1 ? '+' : ' '), 1);
		*s = ft_strjoin(str, *s);
		free(str);
	}
	if (menu->width > ft_strlen(*s))
	{
		c = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - ft_strlen(*s);
		str = ft_memset(ft_strnew(n), c, n);
		str2 = (menu->minus == 0 ? ft_strjoin(str, *s) : ft_strjoin(*s, str));
		free(str);
		free(*s);
		*s = str2;
	}
	if (menu->width > (ft_strlen(*s) - menu->width) && menu->zero != 0 && menu->minus == 0)
	{
		if ((menu->plus == 0 || menu->space == 0) && num >= 0)
			c = (menu->plus == 0 ? ' ' : '+');
		else if (num < 0)
			c = '-';
		*s[0] = c;
		*s[n] = '0';
	}
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
	double_precision(menu, &s, num);
	double_modifiers(menu, &s, num);
	*str = ft_strdup(s);
	free(s);
}
