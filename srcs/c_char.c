/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:55:07 by spentti           #+#    #+#             */
/*   Updated: 2020/01/28 11:50:26 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c_char(t_menu *menu, va_list ap, char **str)
{
	unsigned char	c;
	char			*s;
	char			a;
	int				n;
	char			*temp;
	char			*temp2;

	n = 0;
	temp2 = NULL;
	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	c = (unsigned char)va_arg(ap, int);
	s = ft_memset(ft_strnew(1), c, 1);
	if (menu->width)
	{
		a = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n =  menu->width - 1;
		temp = ft_memset(ft_strnew(n), a, n);
		if (menu->minus == 0)
			temp2 = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			temp2 = ft_strjoin(s, temp);
		free(temp);
		free(s);
		s = temp2;
	}
	*str = ft_strdup(s);
	free(s);
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
	if (s == NULL)
		s = ft_strdup("(null)");
	if (menu->precision < (int)ft_strlen(s))
		s = ft_strndup(s, (size_t)menu->precision);
	if (menu->width > (int)ft_strlen(s))
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
