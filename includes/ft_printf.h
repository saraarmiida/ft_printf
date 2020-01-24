/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:11:40 by spentti           #+#    #+#             */
/*   Updated: 2020/01/24 20:30:58 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_link
{
	char			*str;
	struct s_link	*next;
}					t_link;

typedef struct		s_menu
{
	const char		*format;
	const char		*symbols;
	const char		*conversions;
	int				i;
	int				printed;
	t_link			*head;
	t_link			*link;
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				precision;
	int				length;
}					t_menu;

int					ft_printf(const char *format, ...);
int					parse_format(const char *format, t_menu *menu, va_list ap);
void				conversions(char c, t_menu *menu, va_list ap);
void				modifiers(const char *format, t_menu *menu);

void				c_char(t_menu *menu, va_list ap, char **str);
void				c_string(t_menu *menu, va_list ap, char **str);
void				c_double(t_menu *menu, va_list ap, char **str);
void				c_hex(t_menu *menu, va_list ap, char **str, char x);
void				c_integer(t_menu *menu, va_list ap, char **str);
void				c_octal(t_menu *menu, va_list ap, char **str);
void				c_pointer(t_menu *menu, va_list ap, char **str);
void				c_unsigned(t_menu *menu, va_list ap, char **str);

void				zero_menu(t_menu *menu);
char				*joinlist(t_link *list, int *printed);
int					ft_baselen(unsigned long long n, int base);
char				*ft_itoa_base(unsigned long long n, int base);
void				get_width(t_menu *menu, char **s);
void				get_length(unsigned long long *num, va_list ap, t_menu *m);
char				*ft_ftoa(long double n, int precision);

#endif
