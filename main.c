/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:09:35 by spentti           #+#    #+#             */
/*   Updated: 2020/01/13 16:59:05 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int		*age;
	char	*name;
	char	class;

	*age = 8;
	name = "Vekkuli";
	class = 'f';
	// printf("printf   : .%+27c.\n", class);
	// ft_printf("ft_printf: .%+27c.\n", class);
	printf("printf   : .%.8p.\n");
	// ft_printf("ft_printf: .%.8p.\n", age);
	return (0);
}
