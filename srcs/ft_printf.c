/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:34:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/27 17:23:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_menu	*create_menu(void)
{
	t_menu	*menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		return (NULL);
	menu->symbols = "cspdiouxXfy%#-+ .*0123456789hLljz";
	menu->conversions = "cspdiouxXfy%";
	menu->i = 0;
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

	menu = create_menu();
	va_start(ap, format);
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (-1);
	if ((mode = parse_format(format, menu, ap)) == 1)
		return (-1);
	else if (mode == 2)
		str = (char *)format;
	else
		str = joinlist(menu->head);
	ft_putstr(str);
	va_end(ap);
	printed = ft_strlen(str);
	free(menu);
	if (mode != 2)
		free(str);
	return (printed);
}
