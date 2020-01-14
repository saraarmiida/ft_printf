/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:56:17 by spentti           #+#    #+#             */
/*   Updated: 2020/01/13 18:32:42 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_baselen(unsigned long n, int base)
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

char		*ft_itoa_base(unsigned long n, int base)
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

void	c_pointer(t_menu *menu, va_list ap, char *str)
{
	int					n;
	char				*s;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	n = 0;
	s = ft_itoa_base(pointer, 16);
	if (menu->width && menu->minus == 0)
	{
		n = menu->width - ft_strlen(s) - 2;
		if (menu->zero != 0)
			ft_putchar_len('0', n);
		else if (menu->zero == 0)
			ft_putchar_len(' ', n);
		ft_putstr("0x");
		ft_putstr(s);
		menu->printed += n;
	}
	else if (menu->width && menu->minus == 1)
	{
		n = menu->width - ft_strlen(s) - 2;
		ft_putstr("0x");
		ft_putstr(s);
		ft_putchar_len(' ', n);
		menu->printed += n;
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(s);
	}
	menu->printed += ft_strlen(s) + 2;
	free(s);
}