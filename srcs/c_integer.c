/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:37:31 by spentti           #+#    #+#             */
/*   Updated: 2020/01/15 16:45:33 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_length(int *integer, va_list ap, t_menu *menu)
{
	if (menu->length)
	{
		if (menu->length == 1)
			*integer = (char)va_arg(ap, int);
		if (menu->length == 2)
			*integer = (short)va_arg(ap, int);
		if (menu->length == 3)
			*integer = (long long)va_arg(ap, int);
		if (menu->length == 4)
			*integer = (long)va_arg(ap, int);
	}
}

void	c_integer(t_menu *menu, va_list ap, char **str)
{
	int		n;
	char	*s;
	int		integer;
	char	c;
	char	*temp;

	if (menu->length)
		get_length(&integer, ap, menu);
	else
		integer = va_arg(ap, int);
	s = ft_itoa(integer);
	if (menu->precision != -1 && menu->precision != 0)
	{
		n = menu->precision - ft_baselen(integer, 10);
		temp = ft_memset(ft_strnew(n), '0', n);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if ((menu->plus || menu->space) && integer > 0)
	{
		temp = ft_memset(ft_strnew(1), (menu->plus == 1 ? '+' : ' '), 1);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->width)
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
