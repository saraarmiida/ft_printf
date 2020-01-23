/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:55:07 by spentti           #+#    #+#             */
/*   Updated: 2020/01/23 16:53:08 by spentti          ###   ########.fr       */
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

void	c_char(t_menu *menu, va_list ap, char **str)
{
	unsigned char	c;
	char			a;
	int				n;
	char			*temp;

	n = 0;
	c = (unsigned char)va_arg(ap, int);
	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->width)
	{
		a = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - 1;
		temp = ft_memset(ft_strnew(n + 1), a, n + 1);
		if (menu->minus == 0)
			temp[n] = c;
		else if (menu->minus == 1)
			temp[0] = c;
		*str = ft_strdup(temp);
		free(temp);
	}
	else
		*str = ft_memset(ft_strnew(1), c, 1);
}

void	c_string(t_menu *menu, va_list ap, char **str)
{
	char	*s;
	char	*temp;
	char	c;
	int		n;

	n = 0;
	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	s = (char *)va_arg(ap, char *);
	if (menu->precision > ft_strlen(s))
		s = ft_strndup(s, (size_t)menu->precision);
	if (menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			s = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			s = ft_strjoin(s, temp);
		free(temp);
	}
	*str = ft_strdup(s);
}
