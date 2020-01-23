/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:55:50 by spentti           #+#    #+#             */
/*   Updated: 2020/01/23 18:05:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_length_hex(unsigned long long *integer, va_list ap, t_menu *menu)
{
	if (menu->length)
	{
		if (menu->length == 1)
			*integer = (unsigned char)va_arg(ap, unsigned int);
		else if (menu->length == 2)
			*integer = (unsigned short)va_arg(ap, unsigned int);
		else if (menu->length == 3)
			*integer = (unsigned long long)va_arg(ap, unsigned long long);
		else if (menu->length == 4)
			*integer = (unsigned long)va_arg(ap, unsigned long);
	}
	else if (menu->length == 0)
		*integer = (unsigned int)va_arg(ap, unsigned int);
}

void	get_width(t_menu *menu, char **s)
{
	char	c;
	int		n;
	char	*temp;
	char	*temp2;

	if (menu->width && menu->width > ft_strlen(*s))
	{
		c = ' ';
		if (menu->minus == 0 && menu->zero != 0 && menu->precision == -1)
			c = '0';
		n = menu->width - ft_strlen(*s);
		if (menu->precision != -1 && menu->precision > ft_strlen(*s))
			n = menu->width - menu->precision;
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			temp2 = ft_strjoin(temp, *s);
		else if (menu->minus == 1)
			temp2 = ft_strjoin(*s, temp);
		free(temp);
		free(*s);
		*s = temp2;
	}
}

char	*hex_modifiers(t_menu *menu, char *s)
{
	char	*temp;
	int		n;

	if (menu->precision != -1 && menu->precision > ft_strlen(s))
	{
		n = menu->precision - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), '0', n);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->hash == 1 && !(menu->width != 0 && menu->zero\
	!= 0 && menu->precision == -1 && menu->minus == 0))
	{
		temp = ft_strdup("0x");
		s = ft_strjoin(temp, s);
	}
	if (menu->width && menu->width > ft_strlen(s))
		get_width(menu, &s);
	if (menu->hash == 1 && (menu->width != 0 && menu->zero\
	!= 0 && menu->precision == -1))
		s[1] = 'x';
	return (s);
}

void	c_hex(t_menu *menu, va_list ap, char **str, char x)
{
	int					n;
	char				*s;
	unsigned long long	integer;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	get_length_hex(&integer, ap, menu);
	if (integer < 0)
		integer = 4294967296 + integer;
	s = ft_itoa_base(integer, 16);
	s = hex_modifiers(menu, s);
	if (x == 'X')
	{
		n = 0;
		while (s[n] != '\0')
		{
			s[n] = ft_toupper(s[n]);
			n++;
		}
	}
	*str = ft_strdup(s);
	free(s);
}
