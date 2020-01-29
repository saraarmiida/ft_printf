/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:13:41 by spentti           #+#    #+#             */
/*   Updated: 2020/01/29 15:05:41 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		free(link->str);
		free(link);
		link = temp;
	}
	return (str);
}
