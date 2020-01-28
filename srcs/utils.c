/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:13:41 by spentti           #+#    #+#             */
/*   Updated: 2020/01/28 11:50:04 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_int_part(long long inum, int precision, long double n)
{
	char	*str1;
	char	*temp;

	str1 = ft_itoa(inum);
	if (precision != 0)
	{
		temp = ft_strjoin(str1, ".");
		free(str1);
		str1 = temp;
	}
	if (n < 0)
	{
		temp = ft_strjoin("-", str1);
		free(str1);
		str1 = temp;
	}
	return (str1);
}

char	*get_float_part(long long inum, int precision, long double n2)
{
	char		*str2;
	int			i;

	i = 0;
	n2 = n2 - inum;
	if (!(str2 = (char *)malloc(sizeof(char) * precision + 1)))
		return (NULL);
	while (i < precision)
	{
		inum = (long long)(n2 * 10);
		str2[i] = inum + '0';
		n2 = n2 * 10 - inum;
		i++;
	}
	str2[i] = '\0';
	inum = (long long)(n2 * 10);
	if (inum >= 5)
		str2[i - 1] += 1;
	return (str2);
}

char	*ft_ftoa(long double n, int precision)
{
	long long	inum;
	char		*str1;
	char		*str2;
	char		*temp;
	long double	n2;

	n2 = (n < 0 ? -n : n);
	inum = (long long)n2;
	str1 = get_int_part(inum, precision, n);
	str2 = get_float_part(inum, precision, n2);
	temp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (temp);
}

void	zero_menu(t_menu *menu)
{
	menu->minus = 0;
	menu->zero = 0;
	menu->plus = 0;
	menu->space = 0;
	menu->hash = 0;
	menu->width = 0;
	menu->precision = -1;
	menu->length = 0;
}

char	*ft_putsubstr(char *str, int i, char *sub)
{
	int	j;

	j = 0;
	while (sub[j] != '\0')
	{
		str[i + j] = sub[j];
		j++;
	}
	free(sub);
	return (str);
}

char	*joinlist(t_link *head)
{
	char	*str;
	t_link	*link;
	t_link	*temp;
	int 	i;
	int		len;

	len = 0;
	i = 0;
	link = head;
	while (link != NULL)
	{
		len += ft_strlen(link->str);
		link = link->next;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	link = head;
	while (i < len)
	{
		str = ft_putsubstr(str, i, link->str);
		i += ft_strlen(link->str);
		temp = link->next;
		free(link);
		link = temp;
	}
	return (str);
}
