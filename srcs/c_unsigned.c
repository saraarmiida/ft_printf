/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:30:19 by spentti           #+#    #+#             */
/*   Updated: 2020/01/21 12:28:53 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_ulength(unsigned int *integer, va_list ap, t_menu *menu)
{
	if (menu->length)
	{
		if (menu->length == 1)
			*integer = (char)va_arg(ap, int);
		if (menu->length == 2)
			*integer = (short)va_arg(ap, int);
		if (menu->length == 3)
			*integer = (long long)va_arg(ap, int);
		if (menu->length == 4)
			*integer = (long)va_arg(ap, int);
	}
}

int	ft_uintlen(unsigned long long int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned long long int n)
{
	char	*str;
	int		i;
	int		len;

	if (n < 0)
		n = 4294967295 + n;
	len = ft_uintlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len - 1;
	if (n == 0)
		str[0] = 48;
	while (n > 0)
	{
		str[i] = 48 + n % 10;
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}


void	c_unsigned(t_menu *menu, va_list ap, char **str)
{
	int					n;
	char				*s;
	unsigned long long	integer;
	char				c;
	char				*temp;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	if (menu->length == 0)
		integer = (unsigned int)va_arg(ap, unsigned int);
	else if (menu->length == 1)
		integer = (unsigned char)va_arg(ap, unsigned int);
	else if (menu->length == 2)
		integer = (unsigned short)va_arg(ap, unsigned int);
	else if (menu->length == 3)
		integer = (unsigned long long)va_arg(ap, unsigned long long);
	else if (menu->length == 4)
		integer = (unsigned long)va_arg(ap, unsigned long);
	s = ft_uitoa(integer);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		n = menu->precision - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), '0', n);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->width && menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 && menu->precision == -1 ? '0' : ' ');
		n = menu->width - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			*str = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			*str = ft_strjoin(s, temp);
		free(temp);
	}
	else
		*str = ft_strdup(s);
	free(s);
}
