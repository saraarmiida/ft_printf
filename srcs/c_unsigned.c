/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:30:19 by spentti           #+#    #+#             */
/*   Updated: 2020/01/24 18:18:40 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_uintlen(unsigned long long int n)
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
	get_length_hex(&integer, ap, menu);
	if (integer < 0)
		integer = 4294967295 + integer;
	s = ft_uitoa(integer);
	if (menu->precision != -1 && menu->precision > ft_strlen(s))
	{
		n = menu->precision - ft_strlen(s);
		temp = ft_memset(ft_strnew(n), '0', n);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	get_width(menu, &s);
	*str = ft_strdup(s);
	free(s);
}
