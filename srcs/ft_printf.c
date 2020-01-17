/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:34:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/17 17:02:37 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	menu->head = NULL;
	zero_menu(menu);
	return (menu);
}

int		ft_printf(const char *format, ...)
{
	int				printed;
	va_list			ap;
	t_menu			*menu;
	int				mode;
	char			*str;

	menu = create_menu(format);
	va_start(ap, format);
	menu->format = format;
	if (!format[0])
	{
		return (0);
	}
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	mode = parse_format(format, menu, ap);
	if (mode == 1)
		return (0);
	else if (mode == 2)
		str = (char *)format;
	else
		str = joinlist(menu->head, &menu->printed);
	ft_putstr(str);
	va_end(ap);
	menu->printed = 2;
	printed = menu->printed;
	free(menu);
	return (ft_strlen(str));
}
