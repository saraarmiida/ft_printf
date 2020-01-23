/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:37:31 by spentti           #+#    #+#             */
/*   Updated: 2020/01/20 16:49:00 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_length(long long int *integer, va_list ap, t_menu *menu)
{
	if (menu->length)
	{
		if (menu->length == 1)
			*integer = (signed char)va_arg(ap, int);
		if (menu->length == 2)
			*integer = (short)va_arg(ap, int);
		if (menu->length == 3)
			*integer = (long long)va_arg(ap, long long);
		if (menu->length == 4)
			*integer = (long)va_arg(ap, long);
	}
	else
	{
		if (menu->length == 0)
			*integer = (int)va_arg(ap, int);
	}
}

void	c_integer(t_menu *menu, va_list ap, char **str)
{
	int					n;
	char				*s;
	long long int		integer;
	char				c;
	char				*temp;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	get_length(&integer, ap, menu);
	s = ft_itoa(integer);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		if (integer < 0)
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
	if ((menu->plus || menu->space) && integer > 0 && menu->precision != -1)
	{
		temp = ft_strdup(menu->plus == 1 ? "+" : " ");
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->width && menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 && menu->precision == -1 ? '0' : ' ');
		n = menu->width - (menu->precision != -1 && menu->precision > ft_strlen(s) ? menu->precision : ft_strlen(s));
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			s = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			s = ft_strjoin(s, temp);
		free(temp);
	}
	if ((menu->plus || menu->space) && integer > 0 && menu->precision == -1 && menu->width > ft_intlen(integer))
		s[0] = menu->plus == 1 ? '+' : ' ';
	else if ((menu->plus || menu->space) && integer > 0 && menu->precision == -1)
	{
		temp = ft_strdup(menu->plus == 1 ? "+" : " ");
		s = ft_strjoin(temp, s);
		free(temp);
	}
	*str = ft_strdup(s);
	free(s);
}
