/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:14:52 by spentti           #+#    #+#             */
/*   Updated: 2020/01/15 16:15:30 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		create_link(t_menu *menu, const char *format)
{
	if (menu->head != NULL)
	{
		if (!(menu->link->next = (t_link *)malloc(sizeof(t_link))))
			return (1);
		menu->link = menu->link->next;
	}
	else if (!(menu->link = (t_link *)malloc(sizeof(t_link))))
		return (1);
	if (!(menu->link->str = ft_strndup(&format[menu->i], ft_strclen(format, menu->i, '%'))))
		return (1);
	menu->link->next = NULL;
	if (menu->head == NULL)
		menu->head = menu->link;
	return (0);
}

int		parse_format(const char *format, t_menu *menu, va_list ap)
{
	while (format[menu->i] != '\0')
	{
		if (create_link(menu, format))
			return (1);
		menu->i += ft_strlen(menu->link->str);
		if (format[menu->i++] == '%')
		{
			if (!(ft_strchr(menu->symbols, format[menu->i])))
				break ;
			if (!(ft_strchr(menu->conversions, format[menu->i])))
				modifiers(format, menu);
			if (ft_strchr(menu->conversions, format[menu->i]))
				conversions(format[menu->i], menu, ap);
		}
	}
	return (0);
}
