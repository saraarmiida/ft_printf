/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:55:07 by spentti           #+#    #+#             */
/*   Updated: 2020/01/13 13:41:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_len(char c, int num)
{
	while (num > 0)
	{
		write(1, &c, 1);
		num--;
	}
}

void	c_char(t_menu *menu, va_list ap)
{
	unsigned char	c;
	int				n;

	n = 0;
	c = (unsigned char)va_arg(ap, int);
	if (menu->width && menu->minus == 0)
	{
		n = menu->width - 1;
		if (menu->zero != 0)
			ft_putchar_len('0', n);
		else if (menu->zero == 0)
			ft_putchar_len(' ', n);
		write(1, &c, 1);
		menu->printed += n;
	}
	else if (menu->width && menu->minus == 1)
	{
		n = menu->width - 1;
		write(1, &c, 1);
		ft_putchar_len(' ', n);
		menu->printed += n;
	}
	else
		write(1, &c, 1);
	menu->printed++;	
}

void	c_string(t_menu *menu, va_list ap)
{
	char	*s;
	int		n;

	n = 0;
	s = (char *)va_arg(ap, char *);
	if (menu->width && menu->minus == 0)
	{
		n = menu->width - ft_strlen(s);
		if (menu->zero != 0)
			ft_putchar_len('0', n);
		else if (menu->zero == 0)
			ft_putchar_len(' ', n);
		ft_putstr(s);
		menu->printed += n;
	}
	else if (menu->width && menu->minus == 1)
	{
		n = menu->width - ft_strlen(s);
		ft_putstr(s);
		ft_putchar_len(' ', n);
		menu->printed += n;
	}
	else
		ft_putstr(s);
	menu->printed += ft_strlen(s);
}
