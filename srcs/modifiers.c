/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:30:29 by spentti           #+#    #+#             */
/*   Updated: 2020/01/10 15:43:34 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags(const char *format, t_menu *menu)
{
	while (ft_strchr("-+ #0", format[menu->i]))
	{
		if (format[menu->i] == '-')
			menu->minus = 1;
		else if (format[menu->i] == '+')
			menu->plus = 1;
		else if (format[menu->i] == ' ')
			menu->space = 1;
		else if (format[menu->i] == '#')
			menu->hash = 1;
		else if (format[menu->i] == '0')
			menu->zero = 1;
		menu->i++;
	}
	if (menu->plus == 1)
		menu->space = 0;
}

void	width(const char *format, t_menu *menu)
{
	if (format[menu->i] >= '0' && format[menu->i] <= '9')
	{
		menu->width = ft_atoi(&format[menu->i]);
		menu->i++;
		while (format[menu->i] >= '0' && format[menu->i] <= '9')
		{
			menu->i++;
			if (format[menu->i] == '*')
			{
				if (menu->width < 0)
				{
					menu->minus = 1;
					menu->width *= -1;
				}
				while (format[menu->i] == '*')
					menu->i++;
			}
		}
	}
}

void	modifiers(const char *format, t_menu *menu)
{

	flags(format, menu);
	width(format, menu);
	// precision(format, menu);
	// length(format, menu);
}