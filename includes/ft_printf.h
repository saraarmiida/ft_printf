/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:11:40 by spentti           #+#    #+#             */
/*   Updated: 2020/01/24 17:16:58 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include			"../libft/includes/libft.h"
#include			<stdarg.h>
#include			<stdio.h>

typedef struct		s_link
{
	char			*str;
	size_t			size;
	struct s_link	*next;
}					t_link;

typedef struct		s_menu
{
	const char		*symbols;
	const char		*format;
	const char 		*conversions;
	t_link			*head;
	t_link			*link;
	int				i;
	int				printed;
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				precisiontf;
	int				precision;
	int				length;
}					t_menu;

void				conversions(char c, t_menu *menu, va_list ap);
void				modifiers(const char *format, t_menu *menu);
int					ft_printf(const char *format, ...);
void				c_char(t_menu *menu, va_list ap, char **str);
void				c_string(t_menu *menu, va_list ap, char **str);
void				c_pointer(t_menu *menu, va_list ap, char **str);
void				ft_putchar_len(char c, int num);
void				c_integer(t_menu *menu, va_list ap, char **str);
int					ft_baselen(unsigned long long n, int base);
void				zero_menu(t_menu *menu);
int					parse_format(const char *format, t_menu *menu, va_list ap);
char				*joinlist(t_link *list, int *printed);
void				c_unsigned(t_menu *menu, va_list ap, char **str);
void				get_length(long long int *integer, va_list ap, t_menu *menu);
void				c_octal(t_menu *menu, va_list ap, char **str);
char				*ft_itoa_base(unsigned long long n, int base);
void				c_hex(t_menu *menu, va_list ap, char **str, char x);
void				debug(int n);
void				c_double(t_menu *menu, va_list ap, char **str);
void				get_width(t_menu *menu, char **s);
void				get_length_hex(unsigned long long *integer, va_list ap, t_menu *menu);

#endif