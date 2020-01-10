/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:11:40 by spentti           #+#    #+#             */
/*   Updated: 2020/01/10 15:38:35 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_menu
{
	const char	*symbols;
	const char	*format;
	const char 	*conversions;
	int			i;
	int			printed;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			width; // 0 - 9
	int			precisiontf; // .
	int			precision; // .#
	int			length; // LL HH H L
}				t_menu;

void			conversions(char c, t_menu *menu, va_list ap);
void			modifiers(const char *format, t_menu *menu);
int				ft_printf(const char *format, ...);

#endif