/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:05:07 by spentti           #+#    #+#             */
/*   Updated: 2020/01/29 15:57:02 by spentti          ###   ########.fr       */
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
		printf("inum: %lld n: %Lf\n", inum, n2 * 10);
		str2[i] = ((n2 * 10 - inum) * 10 > 9) ? inum + '0' + 1 : inum + '0';
		str2[i] = (n2 * 10 > 9 ? '0' : str2[i]);
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