/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:34:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/10 16:28:10 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_menu(t_menu *menu)
{
	menu->minus = 0;
	menu->zero = 0;
	menu->plus = 0;
	menu->space = 0;
	menu->hash = 0;
	menu->width = 0;
	menu->precisiontf = 0;
	menu->precision = 0;
	menu->length = 0;
}

t_menu	*create_menu(const char *format)
{
	t_menu	*menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		return (NULL);
	menu->format = format;
	menu->symbols = "cspdiouxXfy%#-+ .*0123456789hLljz";
	menu->conversions = "cspdiouxXfy%";
	menu->i = 0;
	menu->printed = 0;
	zero_menu(menu);
	return (menu);
}

int		parse_format(const char *format, t_menu *menu, va_list ap)
{
	while (format[menu->i] != '\0')
	{
		if (format[menu->i] != '%' && format[menu->i] != '\0')
			menu->printed += write(1, &format[menu->i], 1);
		else if (format[menu->i++] == '%')
		{
			if (!(ft_strchr(menu->symbols, format[menu->i])))
				break ;
			while (ft_strchr(menu->symbols, format[menu->i]))
			{
				if (ft_strchr(menu->conversions, format[menu->i]))
				{
					conversions(format[menu->i], menu, ap);
					menu->i++;
					zero_menu(menu);
					break ;
				}
				else
					modifiers(format, menu);
			}
			continue;
		}
		menu->i++;
	}
	return (menu->printed);
}

int		ft_printf(const char *format, ...)
{
	int				printed;
	va_list			ap;
	t_menu			*menu;

	menu = create_menu(format);
	va_start(ap, format);
	menu->format = format;
	if (!format[0])
	{
		return (0);
	}
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	printed = parse_format(format, menu, ap);
	va_end(ap);
	free(menu);
	return (0);
}
