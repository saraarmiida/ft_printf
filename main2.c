/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:09:35 by spentti           #+#    #+#             */
/*   Updated: 2020/01/21 13:06:55 by spentti          ###   ########.fr       */
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

void	p(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %p ******************
 	*/

 	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%p ******************\n\n");

 	char	*test;
 	void	*pointer;
 	int		a;

 	pointer = &test;
 	printf("0x%s\n", test = ft_itoa_base((unsigned long long)pointer, 16));
	
 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%p'\n", pointer);
 	printf("'%p'\n", pointer);

 	ft_printf("'% p'\n", &test);
 	printf("'% p'\n", &test);

 	printf("'%10 p'\n", &test);
 	ft_printf("'%10 p'\n", &test);

 	ft_printf("'%15p'\n", &a);
 	printf("'%15p'\n", &a);

 	ft_printf("\nUNDEFINED BEHAVIOUR ZERO: \n'%020p'\n", &a);
 	printf("\nUNDEFINED BEHAVIOUR ZERO: \n'%020p'\n", &a);

 	ft_printf("\n'%-*p'\n", 20, &a);
 	printf("'%-*p'\n", 20, &a);

 	ft_printf("'%*p'\n", 20, &a);
 	printf("'%*p'\n", 20, &a);

 	ft_printf("'%*20.4p'\n", 20, &a);
 	printf("'%*20.4p'\n", 20, &a);

 	//printf("PRINTED: %d\n", ft_printf("'\nUNEDEFINED BHEAVIOUR PRECISION \n%20.30p'\n'%20p'\n", &test, &test));
 	//printf("PRINTED: %d\n", printf("'\nUNEDEFINED BHEAVIOUR PRECISION \n%20.30p'\n'%20p'\n", &test, &test));
	
 }

 void	id(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %i and %d ******************
 	*/
	
 	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%i AND %%d ******************\n\n");

 	long double d = 3.1415926535;
 	long long int lli = 55165;
 	long long int lli_m = 18446744073709551615;
 	int	i = 3;
 	long long int lli_n = -55165;
 	int	i_n = -3;

 	printf( "%Lg\n", d );
	
	
 	// LEFT ALIGNED TESTS START
 	ft_printf("\n******************  LEFT ALIGNED TESTS START ******************\n\n");
	
 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%-+i'\n'%-+lli'\n", i, lli);
 	printf("'%-+i'\n'%-+lli'\n", i, lli);

 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%-i'\n'%-lli'\n", i_n, lli_n);
 	printf("'%-i'\n'%-lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%-+ i'\n'%-+ lli'\n", i, lli);
 	printf("'%-+ i'\n'%-+ lli'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%- i'\n'%- lli'\n", i_n, lli_n);
 	printf("'%- i'\n'%- lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%-10 i'\n'%-10 lli'\n", i, lli);
 	printf("'%-10 i'\n'%-10 lli'\n", i, lli);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%- i'\n'%- lli'\n", i, lli);
 	printf("'%- i'\n'%- lli'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%- .5i'\n'%- .10lli'\n", i, lli);
 	printf("'%- .5i'\n'%- .10lli'\n", i, lli);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%- .i'\n'%- .lli'\n", i, lli);
 	printf("'%- .i'\n'%- .lli'\n", i, lli);

 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%- .0i'\n'%- .0lli'\n", i, lli);
 	printf("'%- .0i'\n'%- .0lli'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%- i'\n'%- lli'\n", i_n, lli_n);
 	printf("'%- i'\n'%- lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);
 	printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%-10.5lld'\n'%-10.5d'\n", lli, i);
 	printf("'%-10.5lld'\n'%-10.5d'\n", lli, i);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-+10.5d'\n", i);
 	printf("'%-+10.5d'\n", i);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+60.20d'\n", i_n);
 	printf("'%-+60.20d'\n", i_n);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%-10.5d'\n", i);
 	printf("'%-10.5d'\n", i);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%-010.5lld'\n'%-10.5d'\n", lli_n, i_n);
 	printf("'%-010.5lld'\n'%-10.5d'\n", lli_n, i_n);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%-lld'\n'%-d'\n", lli, i);
 	printf("'%-lld'\n'%-d'\n", lli, i);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%-+015.10hi.'\n", (short int)92);
 	printf("'%-+015.10hi.'\n", (short int)92);

 	ft_printf("\n****** TEST #19 ******\n\n");
 	printf("'%-020.4lli'\n'%-10.5i'\n", lli_n, i_n);
 	ft_printf("'%-020.4lli'\n'%-10.5i'\n", lli_n, i_n);
	
	
 	// LEFT ALIGNED TEST END
 	ft_printf("\n******************  LEFT ALIGNED TESTS END ******************\n\n");
	

 	// RIGHT ALIGNED TESTS START
	
 	ft_printf("\n******************  RIGHT ALIGNED TESTS START ******************\n\n");
	
 	ft_printf("'%ld'\n", -42);
 	printf("'%ld'\n", -42);

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%+ i'\n'%+ lli'\n", i, lli);
 	printf("'%+ i'\n'%+ lli'\n", i, lli);

 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'% i'\n'% lli'\n", i_n, lli_n);
 	printf("'% i'\n'% lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%10 i'\n'%10 lli'\n", i, lli);
 	printf("'%10 i'\n'%10 lli'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'% i'\n'% lli'\n", i, lli);
 	printf("'% i'\n'% lli'\n", i, lli);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'% .5i'\n'% .10lli'\n", i, lli);
 	printf("'% .5i'\n'% .10lli'\n", i, lli);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'% .i'\n'% .lli'\n", i, lli);
 	printf("'% .i'\n'% .lli'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'% .0i'\n'% .0lli'\n", i, lli);
 	printf("'% .0i'\n'% .0lli'\n", i, lli);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'% i'\n'% lli'\n", i_n, lli_n);
 	printf("'% i'\n'% lli'\n", i_n, lli_n);

 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+.5d'\n'%+.5lld'\n", i, lli);
 	printf("'%+.5d'\n'%+.5lld'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+010.5d'\n'%+010.5lld'\n", i, lli);
 	printf("'%+010.5d'\n'%+010.5lld'\n", i, lli);

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%+010.5d'\n'%+010.5lld'\n", i_n, lli_n);
 	printf("'%+010.5d'\n'%+010.5lld'\n", i_n, lli_n);
	
 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+010d'\n'%+010lld'\n", i, lli);
 	printf("'%+010d'\n'%+010lld'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+0*.5d'\n", 10, i);
 	printf("'%+0*.5d'\n", 10, i);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%010d'\n'%-010d'\n", i, i);
 	printf("'%010d'\n'%-010d'\n", i, i);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%010d'\n'%-+010.5d'\n", i, i);
 	printf("'%010d'\n'%-+010.5d'\n", i, i);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%lld'\n'%d'\n", lli, i);
 	printf("'%lld'\n'%d'\n", lli, i);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%+025.5d'\n", i);
 	printf("'%+025.5d'\n", i);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%+015.10hi.'\n", (short int)92);
 	printf("'%+015.10hi.'\n", (short int)92);
	

 	// RIGHT ALIGNED TESTS END
 	ft_printf("\n******************  RIGHT ALIGNED TESTS END ******************\n\n");
	
 }

void	o(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %o ******************
 	*/
	
 	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%o ******************\n\n");
	
 	// LEFT ALIGNED TESTS START
 	ft_printf("\n******************  LEFT ALIGNED TESTS START ******************\n\n");
	
 	unsigned long long int lli_m = 18446744073709551615;
 	unsigned long long int lli_m_n = -18446744073709551615;
 	int	i = 3;
 	unsigned long long int lli = 6964321;
 	unsigned long long int lli_n = -55165;
 	int	i_n = -3;

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%-o'\n'%-o'\n", i, i_n);
 	printf("'%-o'\n'%-o'\n", i, i_n);
	
 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%-#o'\n'%-#o'\n", i, i_n);
 	printf("'%-#o'\n'%-#o'\n", i, i_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%-#o'\n'%-#llo'\n", i, lli);
 	printf("'%-#o'\n'%-#llo'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%-#o'\n'%-#llo'\n", i, lli);
 	printf("'%-#o'\n'%-#llo'\n", i, lli);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%-+#o'\n'%-+#llo'\n", i_n, lli_m_n);
 	printf("'%-+#o'\n'%-+#llo'\n", i_n, lli_m_n);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%- o'\n'%- llo'\n", i_n, lli);
 	printf("'%- o'\n'%- llo'\n", i_n, lli);
	
 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%o'\n'%#llo'\n", i, lli);
 	printf("'%o'\n'%#llo'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
 	printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30o'\n'%+ll.30o'\n", i, lli);
 	printf("'%+.30o'\n'%+ll.30o'\n", i, lli);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+#50.30o'\n'%-+#50.30llo'\n", i, lli);
 	printf("'%-+#50.30o'\n'%-+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+50.30o'\n'%-+50.30llo'\n", i, lli);	
 	printf("'%-+50.30o'\n'%-+50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
 	printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
 	printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+050.30o'\n'%-+050.30llo'\n", i, lli);	
 	printf("'%-+050.30o'\n'%-+050.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%-+#050o'\n'%-+#050llo'\n", i, lli);
 	printf("'%-+#050o'\n'%-+#050llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%-+050o'\n'%-+050llo'\n", i, lli);
 	printf("'%-+050o'\n'%-+050llo'\n", i, lli);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%-+#050o'\n'%-+#050llo'\n", i, lli);
 	printf("'%-+#050o'\n'%-+#050llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%-+050o'\n'%-+050llo'\n", i, lli);
 	printf("'%-+050o'\n'%-+050llo'\n", i, lli);

 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);
 	printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%-+050.0o'\n'%-+050ll.0o'\n", i, lli);
 	printf("'%-+050.0o'\n'%-+050ll.0o'\n", i, lli);
	
 	// LEFT ALIGNED TEST END
 	ft_printf("\n******************  LEFT ALIGNED TESTS END ******************\n\n");
	
	
 	// RIGHT ALIGNED TESTS START
 	ft_printf("\n******************  RIGHT ALIGNED TESTS START ******************\n\n");

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%o'\n'%o'\n", i, i_n);
 	printf("'%o'\n'%o'\n", i, i_n);
	
 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%#o'\n'%#o'\n", i, i_n);
 	printf("'%#o'\n'%#o'\n", i, i_n);


 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%#o'\n'%#llo'\n", i, lli);
 	printf("'%#o'\n'%#llo'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%#o'\n'%#llo'\n", i, lli);
 	printf("'%#o'\n'%#llo'\n", i, lli);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%+#o'\n'%+#llo'\n", i_n, lli);
 	printf("'%+#o'\n'%+#llo'\n", i_n, lli);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'% o'\n'% llo'\n", i_n, lli);
 	printf("'% o'\n'% llo'\n", i_n, lli);
	
 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%o'\n'%#llo'\n", i, lli);
 	printf("'%o'\n'%#llo'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
 	printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30o'\n'%+ll.30o'\n", i, lli);
 	printf("'%+.30o'\n'%+ll.30o'\n", i, lli);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);	
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
 	printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
 	printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);	
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%+#050o'\n'%+#050llo'\n", i, lli);
 	printf("'%+#050o'\n'%+#050llo'\n", i, lli);


 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);
 	printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%+050.0o'\n'%+050ll.0o'\n", i, lli);
 	printf("'%+050.0o'\n'%+050ll.0o'\n", i, lli);
	
	
 	// RIGHT ALIGNED TESTS END
 	ft_printf("\n******************  RIGHT ALIGNED TESTS END ******************\n\n");
	
 }

void	u(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %u ******************
 	*/

 	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%u******************\n\n");

 	long double d = 3.1415926535;
 	unsigned long long int 	llu = 55165;
 	unsigned long long int 	llu_m = 18446744073709551615;
 	unsigned int			u = 3;
 	long long int llu_n = -55165;
 	int	u_n = -3;

 	printf( "%Lg\n", d );
	
	
 	// LEFT ALIGNED TESTS START
 	ft_printf("\n******************  LEFT ALIGNED TESTS START ******************\n\n");
	
 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%-+u'\n'%-+llu'\n", u, llu);
 	printf("'%-+u'\n'%-+llu'\n", u, llu);

 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%-u'\n'%-llu'\n", u_n, llu_n);
 	printf("'%-u'\n'%-llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%-+ u'\n'%-+ llu'\n", u, llu);
 	printf("'%-+ u'\n'%-+ llu'\n", u, llu);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%- u'\n'%- llu'\n", u_n, llu_n);
 	printf("'%- u'\n'%- llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%-10 u'\n'%-10 llu'\n", u, llu);
 	printf("'%-10 u'\n'%-10 llu'\n", u, llu);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%- u'\n'%- llu'\n", u, llu);
 	printf("'%- u'\n'%- llu'\n", u, llu);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%- .5u'\n'%- .10llu'\n", u, llu);
 	printf("'%- .5u'\n'%- .10llu'\n", u, llu);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%- .u'\n'%- .llu'\n", u, llu);
 	printf("'%- .u'\n'%- .llu'\n", u, llu);

 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%- .0u'\n'%- .0llu'\n", u, llu);
 	printf("'%- .0u'\n'%- .0llu'\n", u, llu);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%- u'\n'%- llu'\n", u_n, llu_n);
 	printf("'%- u'\n'%- llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-10 u'\n'%-10 llu'\n", u_n, llu_n);
 	printf("'%-10 u'\n'%-10 llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%-10.5llu'\n'%-10.5u'\n", llu, u);
 	printf("'%-10.5llu'\n'%-10.5u'\n", llu, u);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-+10.5u'\n",u);
 	printf("'%-+10.5u'\n",u);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+60.20u'\n",u_n);
 	printf("'%-+60.20u'\n",u_n);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%-10.5u'\n",u);
 	printf("'%-10.5u'\n",u);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	printf("'%-020.5llu'\n'%-10.5u'\n", llu_n, u_n);
 	ft_printf("'%-020.5llu'\n'%-10.5u'\n", llu_n, u_n);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%-llu'\n'%-u'\n", llu, u);
 	printf("'%-llu'\n'%-u'\n", llu, u);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%-+015.10hu.'\n", (short int)92);
 	printf("'%-+015.10hu.'\n", (short int)92);

	
 	// LEFT ALIGNED TEST END
 	ft_printf("\n******************  LEFT ALIGNED TESTS END ******************\n\n");
	

 	// RIGHT ALIGNED TESTS START
	
 	ft_printf("\n******************  RIGHT ALIGNED TESTS START ******************\n\n");
	
 	ft_printf("'%ld'\n", -42);
 	printf("'%ld'\n", -42);

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%+ u'\n'%+ llu'\n", u, llu);
 	printf("'%+ u'\n'%+ llu'\n", u, llu);

 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'% u'\n'% llu'\n", u_n, llu_n);
 	printf("'% u'\n'% llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%10 u'\n'%10 llu'\n", u, llu);
 	printf("'%10 u'\n'%10 llu'\n", u, llu);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'% u'\n'% llu'\n", u, llu);
 	printf("'% u'\n'% llu'\n", u, llu);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'% .5u'\n'% .10llu'\n", u, llu);
 	printf("'% .5u'\n'% .10llu'\n", u, llu);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'% .u'\n'% .llu'\n", u, llu);
 	printf("'% .u'\n'% .llu'\n", u, llu);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'% .0u'\n'% .0llu'\n", u, llu);
 	printf("'% .0u'\n'% .0llu'\n", u, llu);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'% u'\n'% llu'\n", u_n, llu_n);
 	printf("'% u'\n'% llu'\n", u_n, llu_n);

 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+.5u'\n'%+.5llu'\n", u, llu);
 	printf("'%+.5u'\n'%+.5llu'\n", u, llu);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+010.5u'\n'%+010.5llu'\n", u, llu);
 	printf("'%+010.5u'\n'%+010.5llu'\n", u, llu);

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%+010.5u'\n'%+010.5llu'\n", u_n, llu_n);
 	printf("'%+010.5u'\n'%+010.5llu'\n", u_n, llu_n);
	
 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+010u'\n'%+010llu'\n", u, llu);
 	printf("'%+010u'\n'%+010llu'\n", u, llu);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+0*.5u'\n", 10, u);
 	printf("'%+0*.5u'\n", 10, u);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%010u'\n'%-010u'\n", u, u);
 	printf("'%010u'\n'%-010u'\n", u, u);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%010u'\n'%-+010.5u'\n", u, u);
 	printf("'%010u'\n'%-+010.5u'\n", u, u);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%llu'\n'%u'\n", llu, u);
 	printf("'%llu'\n'%u'\n", llu, u);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%+025.5u'\n", u);
 	printf("'%+025.5u'\n", u);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%+015.10hu.'\n", (short int)92);
 	printf("'%+015.10hu.'\n", (short int)92);
		

 	// RIGHT ALIGNED TESTS END
 	ft_printf("\n******************  RIGHT ALIGNED TESTS END ******************\n\n");
	
 }

void	x(void)
 {
 	/*
 	** ****************** TESTING ENVIRONMENT WITH %x ******************
 	*/

 	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%x ******************\n\n");
	
 	// LEFT ALIGNED TESTS START
 	ft_printf("\n******************  LEFT ALIGNED TESTS START ******************\n\n");
	
 	unsigned long long int lli_m = 18446744073709551615;
 	unsigned long long int lli_m_n = -18446744073709551615;
 	int	i = 3;
 	unsigned long long int lli = 6964321;
 	unsigned long long int lli_n = -55165;
 	int	i_n = -3;

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%-x'\n'%-x'\n", i, i_n);
 	printf("'%-x'\n'%-x'\n", i, i_n);
	
 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%-#x'\n'%-#x'\n", i, i_n);
 	printf("'%-#x'\n'%-#x'\n", i, i_n);

 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%-#x'\n'%-#llx'\n", i, lli);
 	printf("'%-#x'\n'%-#llx'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%-#x'\n'%-#llx'\n", i, lli);
 	printf("'%-#x'\n'%-#llx'\n", i, lli);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%-+#x'\n'%-+#llx'\n", i_n, lli_m_n);
 	printf("'%-+#x'\n'%-+#llx'\n", i_n, lli_m_n);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%- x'\n'%- llx'\n", i_n, lli);
 	printf("'%- x'\n'%- llx'\n", i_n, lli);
	
 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%x'\n'%#llx'\n", i, lli);
 	printf("'%x'\n'%#llx'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30x'\n'%+#ll.30x'\n", i, lli);
 	printf("'%+#.30x'\n'%+#ll.30x'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30x'\n'%+ll.30x'\n", i, lli);
 	printf("'%+.30x'\n'%+ll.30x'\n", i, lli);

 	ft_printf("\n****** TEST #8.1 ******\n\n");
 	ft_printf("'%+#50.30x'\n'%+#50.30llx'\n", i, lli);
 	printf("'%+#50.30x'\n'%+#50.30llx'\n", i, lli);

 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30x'\n'%+50.30llx'\n", i, lli);
 	printf("'%+50.30x'\n'%+50.30llx'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+#50.30X'\n'%-+#50.30llX'\n", i, lli);
 	printf("'%-+#50.30X'\n'%-+#50.30llX'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+50.30X'\n'%-+50.30llX'\n", i, lli);	
 	printf("'%-+50.30X'\n'%-+50.30llX'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-+#050.30X'\n'%-+#050.30llX'\n", i, lli);
 	printf("'%-+#050.30X'\n'%-+#050.30llX'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);
 	printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-+#050.30X'\n'%-+#050.30llX'\n", i, lli);
 	printf("'%-+#050.30X'\n'%-+#050.30llX'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+050.30X'\n'%-+050.30llX'\n", i, lli);	
 	printf("'%-+050.30X'\n'%-+050.30llX'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%-+#050x'\n'%-+#050llx'\n", i, lli);
 	printf("'%-+#050x'\n'%-+#050llx'\n", i, lli);
	
 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%-+050x'\n'%-+050llx'\n", i, lli);
 	printf("'%-+050x'\n'%-+050llx'\n", i, lli);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%-+#050x'\n'%-+#050llx'\n", i, lli);
 	printf("'%-+#050x'\n'%-+#050llx'\n", i, lli);
	
 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%-+050x'\n'%-+050llx'\n", i, lli);
 	printf("'%-+050x'\n'%-+050llx'\n", i, lli);

 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.x'\n'%-+050ll.x'\n", i, lli);
 	printf("'%-+050.x'\n'%-+050ll.x'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%-+050.0x'\n'%-+050ll.0x'\n", i, lli);
 	printf("'%-+050.0x'\n'%-+050ll.0x'\n", i, lli);

	
 	// LEFT ALIGNED TEST END
 	ft_printf("\n******************  LEFT ALIGNED TESTS END ******************\n\n");
	
	
 	// RIGHT ALIGNED TESTS START
 	ft_printf("\n******************  RIGHT ALIGNED TESTS START ******************\n\n");

 	ft_printf("\n****** TEST #1 ******\n\n");
 	ft_printf("'%x'\n'%x'\n", i, i_n);
 	printf("'%x'\n'%x'\n", i, i_n);
	
 	ft_printf("\n****** TEST #2 ******\n\n");
 	ft_printf("'%#x'\n'%#x'\n", i, i_n);
 	printf("'%#x'\n'%#x'\n", i, i_n);


 	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%#x'\n'%#llx'\n", i, lli);
 	printf("'%#x'\n'%#llx'\n", i, lli);

 	ft_printf("\n****** TEST #4 ******\n\n");
 	ft_printf("'%#x'\n'%#llx'\n", i, lli);
 	printf("'%#x'\n'%#llx'\n", i, lli);

 	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%+#x'\n'%+#llx'\n", i_n, lli);
 	printf("'%+#x'\n'%+#llx'\n", i_n, lli);

 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'% x'\n'% llx'\n", i_n, lli);
 	printf("'% x'\n'% llx'\n", i_n, lli);
	
 	ft_printf("\n****** TEST #6 ******\n\n");
 	ft_printf("'%x'\n'%#llx'\n", i, lli);
 	printf("'%x'\n'%#llx'\n", i, lli);

 	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30X'\n'%+#ll.30X'\n", i, lli);
 	printf("'%+#.30X'\n'%+#ll.30X'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30X'\n'%+ll.30X'\n", i, lli);
 	printf("'%+.30X'\n'%+ll.30X'\n", i, lli);

 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);
 	printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30X'\n'%+50.30llX'\n", i, lli);
 	printf("'%+50.30X'\n'%+50.30llX'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);
 	printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+50.30X'\n'%+50.30llX'\n", i, lli);	
 	printf("'%+50.30X'\n'%+50.30llX'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);
 	printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);
 	printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);
 	printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);	
 	printf("'%+050.30X'\n'%+050.30llX'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%+#050X'\n'%+#050llX'\n", i, lli);
 	printf("'%+#050X'\n'%+#050llX'\n", i, lli);


 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.X'\n'%-+050ll.X'\n", i, lli);
 	printf("'%-+050.X'\n'%-+050ll.X'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%+050.0X'\n'%+050ll.0X'\n", i, lli);
 	printf("'%+050.0X'\n'%+050ll.0X'\n", i, lli);

 	ft_printf("\n****** TEST #21 ******\n\n");
 	ft_printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);
 	printf("'%+#50.30X'\n'%+#50.30llX'\n", i, lli);

 	// RIGHT ALIGNED TESTS END
 	ft_printf("\n******************  RIGHT ALIGNED TESTS END ******************\n\n");

 }

void	f(void)
{
	/*
	** ****************** TESTING ENVIRONMENT WITH %f ******************
	*/

	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%f ******************\n\n");
	
	//LEFT ALIGNED TESTS START
	ft_printf("\n******************  LEFT ALIGNED TESTS START ******************\n\n");

	long double lf = 432232342.0193840923840982309580927350274;
	long double lf_n = -432232342.0193840923840982309580927350274;
	double f = 432232342.01938409238;
	double f_n = -432232342.01938409238;

 	ft_printf("\n****** TEST #1 ******\n\n");
	ft_printf("'%-.*Lf'\n", 50,lf);
	printf("'%-.*Lf'\n", 50,lf);

	ft_printf("\n****** TEST #2 ******\n\n");
	ft_printf("'%-.*Lf'\n", 50,lf_n);
	printf("'%-.*Lf'\n", 50,lf_n);

	ft_printf("\n****** TEST #3 ******\n\n");
	ft_printf("'%-.50Lf'\n", lf);
	printf("'%-.50Lf'\n", lf);

	ft_printf("\n****** TEST #4 ******\n\n");
	ft_printf("'%-.Lf'\n", lf);
	printf("'%-.Lf'\n", lf);

	ft_printf("\n****** TEST #5 ******\n\n");
	ft_printf("'%-.0Lf'\n", lf);
	printf("'%-.0Lf'\n", lf);

	ft_printf("\n****** TEST #6 ******\n\n");
	ft_printf("'%-.0f'\n", 0.0);
	printf("'%-.0f'\n", 0.0);

	ft_printf("\n****** TEST #7 ******\n\n");
	ft_printf("'%-.f'\n", 0.0);
	printf("'%-.f'\n", 0.0);

	ft_printf("\n****** TEST #8 ******\n\n");
	ft_printf("'%--100.50Lf'\n", lf);
	printf("'%--100.50Lf'\n", lf);

	ft_printf("\n****** TEST #9 ******\n\n");
	ft_printf("'%-0100.50Lf'\n", lf);
	printf("'%-0100.50Lf'\n", lf);
	
	ft_printf("\n****** TEST #10 ******\n\n");
	ft_printf("'%-0100.150Lf'\n", lf);
	printf("'%-0100.150Lf'\n", lf);

	ft_printf("\n****** TEST #11 ******\n\n");
	ft_printf("'%-+.30Lf'\n", lf);
	printf("'%-+.30Lf'\n", lf);

	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%-+f'\n'%-+Lf'\n",  f, lf);
 	printf("'%-+f'\n'%-+Lf'\n",  f, lf);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-f'\n'%-Lf'\n", f_n, lf_n);
 	printf("'%-f'\n'%-Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+ f'\n'%-+ Lf'\n", f, lf);
 	printf("'%-+ f'\n'%-+ Lf'\n", f, lf);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%- f'\n'%- Lf'\n", f_n, lf_n);
 	printf("'%- f'\n'%- Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%-10 f'\n'%-10 Lf'\n", f, lf);
 	printf("'%-10 f'\n'%-10 Lf'\n", f, lf);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'%- f'\n'%- Lf'\n", f, lf);
 	printf("'%- f'\n'%- Lf'\n", f, lf);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'%- .5f'\n'%- .10Lf'\n", f, lf);
 	printf("'%- .5f'\n'%- .10Lf'\n", f, lf);

 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%- .f'\n'%- .Lf'\n", f, lf);
 	printf("'%- .f'\n'%- .Lf'\n", f, lf);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%- .0f'\n'%- .0Lf'\n", f, lf);
 	printf("'%- .0f'\n'%- .0Lf'\n", f, lf);

 	ft_printf("\n****** TEST #21 ******\n\n");
 	ft_printf("'%- f'\n'%- Lf'\n", f_n, lf_n);
 	printf("'%- f'\n'%- Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #23 ******\n\n");
 	ft_printf("'%-10 f'\n'%-10 Lf'\n", f_n, lf_n);
 	printf("'%-10 f'\n'%-10 Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #24 ******\n\n");
 	ft_printf("'%-10.5Lf'\n'%-10.5f'\n", lf, f);
 	printf("'%-10.5Lf'\n'%-10.5f'\n", lf, f);

 	ft_printf("\n****** TEST #25 ******\n\n");
 	ft_printf("'%-+10.5f'\n", f);
 	printf("'%-+10.5f'\n", f);

 	ft_printf("\n****** TEST #26 ******\n\n");
 	ft_printf("'%-+60.20f'\n", f_n);
 	printf("'%-+60.20f'\n", f_n);

 	ft_printf("\n****** TEST #27 ******\n\n");
 	ft_printf("'%-10.5f'\n", f);
 	printf("'%-10.5f'\n", f);

 	ft_printf("\n****** TEST #28 ******\n\n");
 	ft_printf("'%-010.5Lf'\n'%-10.5f'\n", lf_n, f_n);
 	printf("'%-010.5Lf'\n'%-10.5f'\n", lf_n, f_n);

 	ft_printf("\n****** TEST #29 ******\n\n");
 	ft_printf("'%-Lf'\n'%-f'\n", lf, f);
 	printf("'%-Lf'\n'%-f'\n", lf, f);

 	ft_printf("\n****** TEST #30 ******\n\n");
 	printf("'%-020.4Lf'\n'%-10.5f'\n", lf_n, f_n);
 	ft_printf("'%-020.4Lf'\n'%-10.5f'\n", lf_n, f_n);
	
	// LEFT ALIGNED TEST END
	ft_printf("\n******************  LEFT ALIGNED TESTS END ******************\n\n");
	

	
	//RIGHT ALIGNED TESTS START
	ft_printf("\n******************  RIGHT ALIGNED TESTS START ******************\n\n");

	ft_printf("\n****** TEST #1 ******\n\n");
	ft_printf("'%.*Lf'\n", 50,lf);
	printf("'%.*Lf'\n", 50,lf);

	ft_printf("\n****** TEST #2 ******\n\n");
	ft_printf("'%.*Lf'\n", 50,lf_n);
	printf("'%.*Lf'\n", 50,lf_n);

	ft_printf("\n****** TEST #3 ******\n\n");
	ft_printf("'%.50Lf'\n", lf);
	printf("'%.50Lf'\n", lf);

	ft_printf("\n****** TEST #4 ******\n\n");
	ft_printf("'%.Lf'\n", lf);
	printf("'%.Lf'\n", lf);

	ft_printf("\n****** TEST #5 ******\n\n");
	ft_printf("'%.0Lf'\n", lf);
	printf("'%.0Lf'\n", lf);

	ft_printf("\n****** TEST #6 ******\n\n");
	ft_printf("'%.0f'\n", 0.0);
	printf("'%.0f'\n", 0.0);

	ft_printf("\n****** TEST #7 ******\n\n");
	ft_printf("'%.f'\n", 0.0);
	printf("'%.f'\n", 0.0);

	ft_printf("\n****** TEST #8 ******\n\n");
	ft_printf("'%100.50Lf'\n", lf);
	printf("'%100.50Lf'\n", lf);

	ft_printf("\n****** TEST #9 ******\n\n");
	ft_printf("'%0100.50Lf'\n", lf);
	printf("'%0100.50Lf'\n", lf);
	
	ft_printf("\n****** TEST #10 ******\n\n");
	ft_printf("'%0100.150Lf'\n", lf);
	printf("'%0100.150Lf'\n", lf);

	ft_printf("\n****** TEST #11 ******\n\n");
	ft_printf("'%+.30Lf'\n", lf);
	printf("'%+.30Lf'\n", lf);

	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+f'\n'%+Lf'\n",  f, lf);
 	printf("'%+f'\n'%+Lf'\n",  f, lf);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%f'\n'%Lf'\n", f_n, lf_n);
 	printf("'%f'\n'%Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%+ f'\n'%+ Lf'\n", f, lf);
 	printf("'%+ f'\n'%+ Lf'\n", f, lf);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'% f'\n'% Lf'\n", f_n, lf_n);
 	printf("'% f'\n'% Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%10 f'\n'%10 Lf'\n", f, lf);
 	printf("'%10 f'\n'%10 Lf'\n", f, lf);

 	ft_printf("\n****** TEST #17 ******\n\n");
 	ft_printf("'% f'\n'% Lf'\n", f, lf);
 	printf("'% f'\n'% Lf'\n", f, lf);

 	ft_printf("\n****** TEST #18 ******\n\n");
 	ft_printf("'% .5f'\n'% .10Lf'\n", f, lf);
 	printf("'% .5f'\n'% .10Lf'\n", f, lf);

 	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'% .f'\n'% .Lf'\n", f, lf);
 	printf("'% .f'\n'% .Lf'\n", f, lf);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'% .0f'\n'% .0Lf'\n", f, lf);
 	printf("'% .0f'\n'% .0Lf'\n", f, lf);

 	ft_printf("\n****** TEST #21 ******\n\n");
 	ft_printf("'% f'\n'% Lf'\n", f_n, lf_n);
 	printf("'% f'\n'% Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #23 ******\n\n");
 	ft_printf("'%10 f'\n'%10 Lf'\n", f_n, lf_n);
 	printf("'%10 f'\n'%10 Lf'\n", f_n, lf_n);

 	ft_printf("\n****** TEST #24 ******\n\n");
 	ft_printf("'%10.5Lf'\n'%10.5f'\n", lf, f);
 	printf("'%10.5Lf'\n'%10.5f'\n", lf, f);

 	ft_printf("\n****** TEST #25 ******\n\n");
 	ft_printf("'%+10.5f'\n", f);
 	printf("'%+10.5f'\n", f);

 	ft_printf("\n****** TEST #26 ******\n\n");
 	ft_printf("'%+60.20f'\n", f_n);
 	printf("'%+60.20f'\n", f_n);

 	ft_printf("\n****** TEST #27 ******\n\n");
 	ft_printf("'%10.5f'\n", f);
 	printf("'%10.5f'\n", f);

 	ft_printf("\n****** TEST #28 ******\n\n");
 	ft_printf("'%010.5Lf'\n'%10.5f'\n", lf_n, f_n);
 	printf("'%010.5Lf'\n'%10.5f'\n", lf_n, f_n);

 	ft_printf("\n****** TEST #29 ******\n\n");
 	ft_printf("'%Lf'\n'%f'\n", lf, f);
 	printf("'%Lf'\n'%f'\n", lf, f);

 	ft_printf("\n****** TEST #30 ******\n\n");
	ft_printf("'%020.4Lf'\n'%10.5f'\n", lf_n, f_n);
 	printf("'%020.4Lf'\n'%10.5f'\n", lf_n, f_n);


	//RIGHT ALIGNED TESTS START
	ft_printf("\n******************  RIGHT ALIGNED TESTS END ******************\n\n");

}

int	main(void)
{
	// simple();
	// c();
	// s();
	// p();
	id();
	o();
	u();
	// x();
	// f();	
	return (0);
}
