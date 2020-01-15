/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unsinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:30:19 by spentti           #+#    #+#             */
/*   Updated: 2020/01/15 17:05:12 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_ulength(unsigned int *integer, va_list ap, t_menu *menu)
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

void	c_unsinteger(t_menu *menu, va_list ap, char **str)
{
	int				n;
	char			*s;
	int				integer2;
	unsigned int	integer;
	char			c;
	char			*temp;

	if (menu->length)
		get_ulength(&integer, ap, menu);
	else
		integer2 = va_arg(ap, int);
	if (integer2 < 0)
	{
		integer = 4294967295 + integer2;
		printf("int: %u\n", integer);
	}
	s = ft_itoa();
	if (menu->precision != -1 && menu->precision != 0)
	{
		n = menu->precision - ft_baselen(integer, 10);
		temp = ft_memset(ft_strnew(n), '0', n);
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
