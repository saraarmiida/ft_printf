/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:09:35 by spentti           #+#    #+#             */
/*   Updated: 2020/01/17 17:38:25 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	simple(void)
{	
 	/*
 	** ****************** Simple string without any variables ******************
 	*/
	
 	printf("SIMPLE STRING TEST WITHOUT ANY VARIABLES\n");

 	ft_printf("This is a String\n");
 	printf("%d\n", ft_printf("This is a String\n"));

}

void	c(void)
{
 	/*
 	** ******************  TESTING ENVIRONMENT WITH %c******************
 	*/

 	printf("\n******************  TESTING ENVIRONMENT WITH %%c ******************\n\n");

 	char c = 'A';
 	char b = 'B';

 	// printf("Chars printed: %d\n", ft_printf("'%-010c'\n", c));
	
 	ft_printf("1.1:  '%-*c'\n'%-10c'\n", 10, c, b);
 	printf("1.2:  '%-*c'\n'%-10c'\n", 10, c, b);
	printf("\n");
 	ft_printf("2.1:  '%*c'\n'%10c'\n", 10, c, b);
 	printf("2.2:  '%*c'\n'%10c'\n", 10, c, b);
	printf("\n");
 	ft_printf("3.1:  '%%%*c%%'\n'%%%10c%%'\n", 10, c, b);
 	printf("3.2:  '%%%*c%%'\n'%%%10c%%'\n", 10, c, b);
}

 void	s(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %s ******************
 	*/

 	printf("\n******************  TESTING ENVIRONMENT WITH %%s ******************\n\n");

 	char *str = "Hello World";

 	ft_printf("'%-015s'\n'%15c'\n", str, c);
 	printf("'%-015s'\n'%15c'\n\n", str, c);
	
 	ft_printf("'%-0*s'\n'%15c'\n", 15, str, c);
 	printf("'%-0*s'\n'%15c'\n\n", 15, str, c);
	
 	ft_printf("'%15.s'\n", str);
 	printf("'%15.s'\n\n", str);

 	ft_printf("'%15.0s'\n", str);
 	printf("'%15.0s'\n\n", str);

 	ft_printf("'%-15.0006s'\n", str);
 	printf("'%-15.0006s'\n\n", str);

 	ft_printf("'%*.6s'\n", 15, str);
 	printf("'%*.6s'\n\n", 15, str);
 }

int	main(void)
{
	unsigned int	*age;
	char	*name;
	char	*voi;
	char	class;
	double	fnum;

	*age = -39576;
	name = "Vekkuli";
	voi = "voivoi";
	class = 'f';
	fnum = -267194578.776927592;
	// printf("printf   : .%c.\n", class);		// char
	// ft_printf("ft_printf: .%c.\n", class);
	// printf("printf   : .%-20p.\n", age);				// pointer
	// ft_printf("ft_printf: .%-20p.\n", age);
	// printf("printf   : .%5.0s.\n", name);					// string
	// ft_printf("ft_printf: .%5.0s.\n", name);
	// printf("printf   : .%X.\n", *age);					// integer
	// ft_printf("ft_printf: .%X.\n", *age);
	// printf("printf   : .%2f.\n", fnum);					// integer
	// ft_printf("ft_printf: .%2f.\n", fnum);
	ft_printf("This is a%% String\n");
	// simple();
	// c();
	// s();
	// p();
	// id();
	// o();
	// u();
	// x();
	// f();	
	return (0);
}
