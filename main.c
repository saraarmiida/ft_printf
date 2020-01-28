/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:13:36 by spentti           #+#    #+#             */
/*   Updated: 2020/01/28 16:10:44 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

// int	main(void)
// {
// 	int	*age;
// 	char	*name;
// 	char	*voi;
// 	char	class;
// 	double	fnum;
// 	int	i = -3;
//  	unsigned long long int lli = 6964321;
// 	long double d = 3.1415926535;
//  	unsigned long long int 	llu = 5516582965;
//  	unsigned int			u = 0;
//  	long long int llu_n = -55165;
//  	int	u_n = -3;
// 	long double lf = -432232342.0193840923840982309580927350274;
// 	long double lf_n = -432232342.0193840923840982309580927350274;
// 	double f = 432232342.01938409238;
// 	double f_n = -432232342.01938409238;
// 	int	res1;
// 	int res2;
// 	char	*str = "Hello World";
// 	int		a;

// 	*age = 3687;
// 	name = "Vekkuli";
// 	voi = "voivoi";
// 	class = 'f';
// 	fnum = 267199.77656565655;
// 	res2 = ft_printf("%-5");
// 	// res1 = printf("%-5");
// 	// ft_printf("\n  res1: %d res2: %d\n", res1, res2);
// 	return (0);
// }

int				main(void)
{
  ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);
  while (1);
  return (0);
}
