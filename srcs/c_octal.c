/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_octal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:00:23 by spentti           #+#    #+#             */
/*   Updated: 2020/01/20 17:27:03 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned long long n, int base)
{
	char	*str;
	int		i;
	int		len;

	len = ft_baselen(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len - 1;
	if (n == 0)
		str[0] = 48;
	while (n > 0)
	{
		str[i] = (n % base < 10) ? '0' + n % base : n % base + 'a' - 10;
		n = n / base;
		i--;
	}
	str[len] = '\0';
	return (str);
}

void	c_octal(t_menu *menu, va_list ap, char **str)
{
	int					n;
	char				*s;
	unsigned long long	integer;
	char				c;
	char				*temp;

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
	if (integer < 0)
		integer = 4294967296 + integer;
	s = ft_itoa_base(integer, 8);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		n = menu->precision - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), '0', n);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->hash == 1 && s[0] != '0')
	{
		temp = ft_strdup("0");
		s = ft_strjoin(temp, s);
	}
	if (menu->width && menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 && menu->precision == -1 ? '0' : ' ');
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
