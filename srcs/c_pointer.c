/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:56:17 by spentti           #+#    #+#             */
/*   Updated: 2020/01/20 17:04:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_baselen(unsigned long long n, int base)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n += -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_hex(unsigned long n, int base)
{
	char	*str;
	int		i;
	int		len;

	len = ft_baselen(n, base) + 2;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len - 1;
	str[0] = '0';
	str[1] = 'x';
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

void	c_pointer(t_menu *menu, va_list ap, char **str)
{
	int					n;
	char				*s;
	unsigned long long	pointer;
	char				c;
	char				*temp;

	if (menu->width == -2)
		menu->width = (int)va_arg(ap, int);
	if (menu->precision == -2)
		menu->precision = (int)va_arg(ap, int);
	pointer = (unsigned long long)va_arg(ap, void *);
	n = 0;
	s = ft_itoa_base_hex(pointer, 16);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
		s = ft_strndup(s, (size_t)menu->precision + 2);
	if (menu->width && ft_strlen(s) < menu->width)
	{
		c = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
		n = menu->width - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), c, n);
		if (menu->minus == 0)
			s = ft_strjoin(temp, s);
		else if (menu->minus == 1)
			s = ft_strjoin(s, temp);
		free(temp);
		if (menu->minus == 0 && menu->zero != 0)
		{
			s[1] = 'x';
			s[n + 1] = '0';
		}
	}
	*str = ft_strdup(s);
	free(s);
}
