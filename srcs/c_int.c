/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:37:31 by spentti           #+#    #+#             */
/*   Updated: 2020/01/24 17:02:24 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_length(long long int *integer, va_list ap, t_menu *menu)
{
	if (menu->length == 0)
		*integer = (int)va_arg(ap, int);
	else if (menu->length == 1)
		*integer = (signed char)va_arg(ap, int);
	else if (menu->length == 2)
		*integer = (short)va_arg(ap, int);
	else if (menu->length == 3)
		*integer = (long long)va_arg(ap, long long);
	else if (menu->length == 4)
		*integer = (long)va_arg(ap, long);
}

void	int_precision(t_menu *menu, char **s, long long integer)
{
	char	*temp;
	char	*temp2;
	int		n;

	if (integer < 0)
	{
		n = menu->precision - ft_strlen(*s) + 2;
		temp = ft_memset(ft_strnew(n), '0', n);
		temp[0] = '-';
		*s = ft_strjoin(temp, *s + 1);
		free(temp);
	}
	else
	{
		n = menu->precision - ft_strlen(*s);
		temp = ft_memset(ft_strnew(n), '0', n);
		*s = ft_strjoin(temp, *s);
		free(temp);
	}
}

void	int_plus(t_menu *menu, char **s, long long integer)
{
	char	*temp;
	char	*temp2;

	if ((menu->plus || menu->space) && integer > 0)
	{
		temp2 = (menu->plus == 1 ? "+" : " ");
		temp = ft_strjoin(temp2, *s);
		free(*s);
		*s = temp;
	}
}

void	int_width(t_menu *menu, char **s, long long integer)
{
	char	*temp;
	char	c;
	int		n;

	c = ' ';
	if (menu->minus == 0 && menu->zero != 0 && menu->precision == -1)
		c = '0';
	n = menu->width - ft_strlen(*s);
	if (menu->precision != -1 && menu->precision > ft_strlen(*s))
		n = menu->width - menu->precision;
	temp = ft_memset(ft_strnew(n), c, n);
	*s = (menu->minus == 0 ? ft_strjoin(temp, *s) : ft_strjoin(*s, temp));
	free(temp);
	if (c == '0' && (integer < 0 || (menu->plus == 1 && integer >= 0)))
	{
		temp = *s;
		temp[0] = (integer < 0 ? '-' : '+');
		temp[n] = '0';
		*s = temp;
	}
}

void	c_integer(t_menu *menu, va_list ap, char **str)
{
	char				*s;
	long long int		integer;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	get_length(&integer, ap, menu);
	s = ft_itoa(integer);
	if (menu->precision != -1 && menu->precision > ft_strlen(s))
		int_precision(menu, &s, integer);
	int_plus(menu, &s, integer);
	if (menu->width && menu->width > ft_strlen(s))
		int_width(menu, &s, integer);
	*str = ft_strdup(s);
	free(s);
}
