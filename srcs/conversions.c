/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:45:01 by spentti           #+#    #+#             */
/*   Updated: 2020/01/13 14:10:05 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversions(char c, t_menu *menu, va_list ap)
{
	if (c == 'c')
		c_char(menu, ap);
	else if (c == 's')
		c_string(menu, ap);
	else if (c == 'p')
		c_pointer(menu, ap);
}