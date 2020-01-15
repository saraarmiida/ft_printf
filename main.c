/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:09:35 by spentti           #+#    #+#             */
/*   Updated: 2020/01/15 16:39:11 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int		*age;
	char	*name;
	char	*voi;
	char	class;

	*age = -48;
	name = "Vekkuli";
	voi = "voivoi";
	class = 'f';
	// printf("printf   : .%c.\n", class);		// char
	// ft_printf("ft_printf: .%c.\n", class);
	// printf("printf   : .%-20p.\n", age);				// pointer
	// ft_printf("ft_printf: .%-20p.\n", age);
	// printf("printf   : .%5.0s.\n", name);					// string
	// ft_printf("ft_printf: .%5.0s.\n", name);
	printf("printf   : .%u.\n", *age);					// integer
	ft_printf("ft_printf: .%u.\n", *age);
	return (0);
}
