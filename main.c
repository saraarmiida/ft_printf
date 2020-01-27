/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:13:36 by spentti           #+#    #+#             */
/*   Updated: 2020/01/27 18:02:59 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	*age;
	char	*name;
	char	*voi;
	char	class;
	double	fnum;
	int	i = -3;
 	unsigned long long int lli = 6964321;
	long double d = 3.1415926535;
 	unsigned long long int 	llu = 5516582965;
 	unsigned int			u = 0;
 	long long int llu_n = -55165;
 	int	u_n = -3;
	long double lf = -432232342.0193840923840982309580927350274;
	long double lf_n = -432232342.0193840923840982309580927350274;
	double f = 432232342.01938409238;
	double f_n = -432232342.01938409238;
	int	res1;
	int res2;
	char	*str = "Hello World";
	int		a;

	*age = 3687;
	name = "Vekkuli";
	voi = "voivoi";
	class = 'f';
	fnum = 267199.77656565655;
	res1 = printf("%c", NULL);
	res2 = ft_printf("%c", NULL);
	ft_printf("\n  res1: %d res2: %d\n", res1, res2);
	return (0);
}
