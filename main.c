/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:09:35 by spentti           #+#    #+#             */
/*   Updated: 2020/01/14 18:49:06 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int		*age;
	char	*name;
	char	*voi;
	char	class;

	*age = 8;
	name = "Vekkuli";
	voi = "voivoi";
	class = 'f';
	// printf("printf   : .%+27c.\n", class);		// char
	// ft_printf("ft_printf: .%+27c.\n", class);
	// printf("printf   : .%.8p.\n");				// pointer
	// ft_printf("ft_printf: .%.8p.\n", age);
	// printf("printf   : .%s.\n", name);					// string
	ft_printf("ft_printf: %s %s after\n", name, voi);
	
	return (0);
}
