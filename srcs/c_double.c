/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:01:25 by spentti           #+#    #+#             */
/*   Updated: 2020/01/21 18:08:48 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_to_str(long long length, long long i, long long position, long long sign, long long inum, long long fnum)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	while (i >= 0) 
	{
		if (i == length)
			str[i] = '\0';
		else if (i == position)
			str[i] = '.';
		else if (sign == -1 && i == 0)
			str[i] = '-';
		else if (i > position)
		{
			str[i] = (fnum % 10) + '0';
			fnum /= 10;
		}
		else if (i < position)
		{
			str[i] = (inum % 10) + '0';
			inum /= 10;
		}
		i--;
	}
	return (str);
}

long long	ft_pow(int num, int power)
{
	long long	res;
	int			i;
	
	i = 1;
	res = num;
	while (i++ < power)
		res = res * num;
	return (res);
}

char	*ft_ftoa(long double n, int precision)
{
	long long int	length;
	long long int	i;
	long long int	inum;
	long long int	fnum;
	long long int	fnum2;
	long long int	position;
	long long int	sign;
	long double		n2;
	char			*str;
	
	sign = (n < 0 ? -1 : 1);
	n = (n < 0 ? -n : n);
	inum = (long long int)n;
	length = ft_intlen(inum);
	position = length;
	length = length + 1 + precision;
	if (sign == -1)
	{
		length++;
		position++;
	}
	if (precision > 17)
	{
		n2 = (n - inum) * ft_pow(10, 17);
		fnum = (n - inum) * ft_pow(10, 17);
		fnum2 = (n2 - fnum) * ft_pow(10, precision - 16);
	}
	printf("n2: %Lf, fnum: %lld, fnum2: %lld\n", n2, fnum, fnum2);
	fnum = (n - inum) * ft_pow(10, precision + 1);
	i = length;
	str = int_to_str(length + 1, i, position, sign, inum, fnum);
	if (str[length] >= '0' + 5)
		str[length - 1] += 1;
	str[length] = '\0';
	return (str);
}

void	c_double(t_menu *menu, va_list ap, char **str)
{
	int			n;
	char		*s;
	long double	num;
	char		c;
	char		*temp;

	if (menu->length)
		num = (long double)va_arg(ap, long double);
	else
		num = (long double)va_arg(ap, double);
	if (menu->precision == -1)
		menu->precision = 6;
	s = ft_ftoa(num, menu->precision);
	if (menu->precision != -1 && menu->precision != 0 && menu->precision > ft_strlen(s))
	{
		if (num < 0)
		{
			n = menu->precision - ft_strlen(s) + 2;
			temp = ft_memset(ft_strnew(n), '0', n);
			temp[0] = '-';
			s = ft_strjoin(temp, s + 1);
			free(temp);
		}
		else
		{
			n = menu->precision - ft_strlen(s);
			temp = ft_memset(ft_strnew(n), '0', n);
			s = ft_strjoin(temp, s);
			free(temp);
		}
	}
	if ((menu->plus || menu->space) && num > 0)
	{
		temp = ft_memset(ft_strnew(1), (menu->plus == 1 ? '+' : ' '), 1);
		s = ft_strjoin(temp, s);
		free(temp);
	}
	if (menu->width && menu->width > ft_strlen(s))
	{
		c = (menu->minus == 0 && menu->zero != 0 ? '0' : ' ');
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
