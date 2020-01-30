/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:55:07 by spentti           #+#    #+#             */
/*   Updated: 2020/01/30 17:05:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*char_width(t_menu *menu, char *s, int len)
{
	char	a;
	int		n;
	char	*temp;

	a = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
	n = menu->width - len;
	temp = ft_memset(ft_strnew(n), a, n);
	if (menu->minus == 0)
		s = join_free(temp, s);
	else
		s = join_free(s, temp);
	return (s);
}

void	c_char(t_menu *menu, va_list ap, char **str)
{
	unsigned char	c;
	char			*s;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	c = (unsigned char)va_arg(ap, int);
	s = (c == '\0' ? ft_strdup("^@") : ft_memset(ft_strnew(1), c, 1));
	menu->null_c = (c == 0 ? 1 : 0);
	if (menu->width)
		s = char_width(menu, s, 1);
	*str = ft_strdup(s);
	free(s);
}

void	c_string(t_menu *menu, va_list ap, char **str)
{
	char	*s;
	char	*temp;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	s = (char *)va_arg(ap, char *);
	s = (s == NULL ? ft_strdup("(null)") : ft_strdup(s));
	if (menu->precision != -1 && menu->precision < (int)ft_strlen(s))
	{
		temp = ft_strndup(s, (size_t)menu->precision);
		free(s);
		s = temp;
	}
	if (menu->width > (int)ft_strlen(s))
		s = char_width(menu, s, ft_strlen(s));
	*str = ft_strdup(s);
	free(s);
}

void	percent_sign(t_menu *menu, char **str)
{
	char	a;
	int		n;
	char	*temp;

	if (menu->width)
	{
		a = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - 1;
		temp = ft_memset(ft_strnew(n + 1), a, n + 1);
		if (menu->minus == 0)
			temp[n] = '%';
		else if (menu->minus == 1)
			temp[0] = '%';
		*str = ft_strdup(temp);
		free(temp);
	}
	else
		*str = ft_memset(ft_strnew(1), '%', 1);
}
