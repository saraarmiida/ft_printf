/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:13:41 by spentti           #+#    #+#             */
/*   Updated: 2020/01/15 16:16:22 by spentti          ###   ########.fr       */
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
	menu->precisiontf = 0;
	menu->precision = -1;
	menu->length = 0;
}

char	*joinlist(t_link *list, int *printed)
{
	char	*str;
	char	*temp;

	str = NULL;
	while (list != NULL)
	{
		if (str == NULL)
			str = list->str;
		else
		{
			temp = ft_strjoin(str, list->str);
			free(str);
			str = temp;
		}
		list = list->next;
	}
	*printed = ft_strlen(str);
	return (str);
}
