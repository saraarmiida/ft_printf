/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:45:01 by spentti           #+#    #+#             */
/*   Updated: 2020/01/10 16:12:29 by spentti          ###   ########.fr       */
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
	// printf("char: %d", c);
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

void	conversions(char c, t_menu *menu, va_list ap)
{
	if (c == 'c')
		c_char(menu, ap);
	// else if (c == 's')
	// 	c_string(menu, ap);
}