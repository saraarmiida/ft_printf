/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:34:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/09 18:12:34 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	x;
	char			*s;
	va_list			ap;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
		}
		i++;
		if (format[i] == 'c')
			ft_putchar(va_arg(ap, int));
		else if (format[i] == 'd')
			ft_putnbr(va_arg(ap, int));
		else if (format[i] == 's')
			ft_putstr(va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int		age;
	char	*name;
	char	class;

	age = 8;
	name = "Vekkuli";
	class = 'f';
	printf("Moi %s %dv luokalta %c\n", name, age, class);
	ft_printf("Moi %s %dv luokalta %c\n", name, age, class);
	return (0);
}
