/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:34:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/14 18:45:54 by spentti          ###   ########.fr       */
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
	menu->head = NULL;
	zero_menu(menu);
	return (menu);
}

int		parse_format(const char *format, t_menu *menu, va_list ap)
{
	while (format[menu->i] != '\0')
	{
		if (menu->head != NULL)
		{
			if (!(menu->link->next = (t_link *)malloc(sizeof(t_link))))
			return (0);
			menu->link = menu->link->next;
		}
		else if (!(menu->link = (t_link *)malloc(sizeof(t_link))))
			return (0);
		if (!(menu->link->str = ft_strndup(&format[menu->i], ft_strclen(format, menu->i, '%'))))
			return (0);
		menu->link->next = NULL;
		if (menu->head == NULL)
			menu->head = menu->link;
		menu->i += ft_strlen(menu->link->str);
		if (format[menu->i++] == '%')
		{
			if (!(ft_strchr(menu->symbols, format[menu->i])))
				break ;
			while (ft_strchr(menu->symbols, format[menu->i]))
			{
				if (ft_strchr(menu->conversions, format[menu->i]))
				{
					conversions(format[menu->i], menu, ap);
					zero_menu(menu);
					break ;
				}
				else
					modifiers(format, menu);
			}
		}
	}
	return (menu->printed);
}

char	*joinlist(t_link *list)
{
	char	*str;
	char	*temp;

	str = NULL;
	if (list->next != NULL)
	{
		while (list != NULL)
		{
			if (str == NULL)
			{
				str = ft_strjoin(list->str, list->next->str);
				list = list->next->next;
			}
			else
			{
				temp = ft_strjoin(str, list->str);
				free(str);
				str = temp;
				list = list->next;
			}
		}
	}
	else
		str = list->str;
	return (str);
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
	ft_putstr(joinlist(menu->head));
	va_end(ap);
	free(menu);
	return (printed);
}
