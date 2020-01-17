/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:13:41 by spentti           #+#    #+#             */
/*   Updated: 2020/01/17 17:14:51 by spentti          ###   ########.fr       */
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
	menu->precisiontf = 6;
	menu->precision = -1;
	menu->length = 0;
}

void	debug(int n)
{
	ft_putstr("SHIT");
	ft_putnbr(n);
	ft_putendl("");
}

char	*joinlist(t_link *list, int *printed)
{
	char	*str;
	char	*temp;
	t_link	*templ;

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
		// free(list->str);
		if (list->next == NULL)
			break ;
		templ = list->next;
		free(list);
		list = templ;
	}
	*printed = ft_strlen(str);
	return (str);
}
