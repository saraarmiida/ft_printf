/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:55:50 by spentti           #+#    #+#             */
/*   Updated: 2020/01/16 14:39:51 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c_hex(t_menu *menu, va_list ap, char **str, char x)
{
	int				n;
	char			*s;
	unsigned long	integer;
	char			c;
	char			*temp;

	if (menu->length == 0)
		integer = (unsigned int)va_arg(ap, unsigned int);
	else if (menu->length == 1)
		integer = (unsigned char)va_arg(ap, unsigned int);
	else if (menu->length == 2)
		integer = (unsigned short)va_arg(ap, unsigned int);
	else if (menu->length == 3)
		integer = (unsigned long long)va_arg(ap, unsigned long long);
	else if (menu->length == 4)
		integer = (unsigned long)va_arg(ap, unsigned long);
	if (integer < 0)
		integer = 4294967296 + integer;
	s = ft_itoa_base(integer, 16);
	if (x == 'X')
	{
		n = 0;
		while (s[n] != '\0')
		{
			s[n] = ft_toupper(s[n]);
			n++;
		}
	}
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		n = menu->precision - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), '0', n);
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
