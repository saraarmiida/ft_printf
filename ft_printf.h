/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:11:40 by spentti           #+#    #+#             */
/*   Updated: 2020/01/09 18:16:51 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_menu
{
	char		*format;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			width; // 0 - 9
	int			precisiontf; // .
	int			precision; // .#
	int			length; // LL HH H L
}				t_menu;

#endif