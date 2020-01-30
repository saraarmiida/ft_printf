/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:13:41 by spentti           #+#    #+#             */
/*   Updated: 2020/01/30 16:47:06 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*join_free(char *str1, char *str2)
{
	char	*joined;

	joined = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (joined);
}

void	free_multiple(void *s1, void *s2, void *s3)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s3);
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
	return (str);
}

char	*joinlist(t_link *head)
{
	char	*str;
	t_link	*link;
	t_link	*temp;
	int		i;
	int		len;

	len = 0;
	i = 0;
	link = head;
	while (link != NULL)
	{
		len += ft_strlen(link->str);
		link = link->next;
	}
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (i < len)
	{
		str = ft_putsubstr(str, i, head->str);
		i += ft_strlen(head->str);
		temp = head->next;
		free_multiple(head->str, head, NULL);
		head = temp;
	}
	return (str);
}
