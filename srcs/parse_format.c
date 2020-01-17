/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:14:52 by spentti           #+#    #+#             */
/*   Updated: 2020/01/17 17:37:51 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		create_link(t_menu *menu, const char *format, char delim)
{
	if (menu->head != NULL)
	{
		if (!(menu->link->next = (t_link *)malloc(sizeof(t_link))))
			return (1);
		menu->link = menu->link->next;
	}
	else if (!(menu->link = (t_link *)malloc(sizeof(t_link))))
		return (1);
	if (!(menu->link->str = ft_strndup(&format[menu->i], ft_strclen(format, menu->i, delim))))
		return (1);
	menu->link->next = NULL;
	if (menu->head == NULL)
		menu->head = menu->link;
	menu->i += ft_strlen(menu->link->str);
	return (0);
}

int		parse_format(const char *format, t_menu *menu, va_list ap)
{
	if (ft_strchr(format, '%') == NULL)
		return (2);
	while (format[menu->i] != '\0')
	{
		if (create_link(menu, format, '%'))
			return (1);
		if (format[menu->i++] == '%' && format[menu->i + 1] != '%')
		{
			if (!(ft_strchr(menu->symbols, format[menu->i])))
				break ;
			if (!(ft_strchr(menu->conversions, format[menu->i])))
				modifiers(format, menu);
			if (ft_strchr(menu->conversions, format[menu->i]))
				conversions(format[menu->i], menu, ap);
		}
		else if (format[menu->i++] == '%' && format[menu->i + 1] == '%')
		{
			if (!(menu->link->next = (t_link *)malloc(sizeof(t_link))))
				return (1);
			menu->link = menu->link->next;
			if (!(menu->link->str = ft_strnew(1)))
				return (1);
			menu->link->str[0] = '%';
			menu->link->next = NULL;
			menu->i += ft_strlen(menu->link->str);
		}
		
	}
	return (0);
}
