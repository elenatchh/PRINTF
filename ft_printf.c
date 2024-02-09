/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melondeau <melondeau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:54:03 by elefonta          #+#    #+#             */
/*   Updated: 2024/02/09 14:11:39 by melondeau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;

	count = 0;
	if (!format)
		return(0);
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_args(*format, arguments, format);
			format++;
		}
		else
		{
  			count += ft_print_char(*format);
		}
		format++;
	}
	va_end(arguments);
	return (count);
}

int	ft_print_args(char type, va_list argument, const char *format)
{
	if (type == 'c')
		return (ft_print_char(va_arg(argument, int)));
	if (type == 's')
		return (ft_print_str(va_arg(argument, char *)));
	if (type == 'd' || type == 'i')
		return (ft_print_nbr(va_arg(argument, int)));
	if (type == '%')
		return (ft_print_char('%'));
	if (type == 'u')
		return (ft_print_unsigned(va_arg(argument, unsigned int)));
	if (type == 'x')
		return (ft_print_nbr_base(va_arg(argument, unsigned int),
				LOWER_HEX, format));
	if (type == 'X')
		return (ft_print_nbr_base(va_arg(argument, unsigned int),
				UPPER_HEX, format));
	if (type == 'p')
		return (ft_print_nbr_base((unsigned long long)va_arg(argument, void *),
				LOWER_HEX, format));
	return (0);
}
#include <stdio.h>

int main() {
    char nom[] = "John";  
    int nombre = 42;
    int nbr = -12;
    unsigned int test = 125; 
    unsigned int testx = 125;
    unsigned int testxe = 125;

    printf("Bonjour %s, il y a %i points\nTu veux %d bananes?\nHehe %% LOL \nOn tente %u,\nMaintenant, on va voir les x : %x voilà \nMaintenant, on voit les X : %X\n", nom, nombre, nbr, test, testx, testxe);
	ft_printf("bonjour %s \n,il y a %i points\n",nom, nombre);
    return 0;
}


// int main (void)
// {
// 	char c = 'c';
// 	printf("%d", printf("abc%"));	
// 	printf("\n");
// 	printf("%d", ft_printf("abc%"));
// }



// int main()
// {

// 	ft_printf("%d", -123456677);
// 	printf("\n");
// 	printf("%d", -123456677 );
// 	ft_printf("%d", -1234566733333337);
// 	printf("\n");
// 	ft_printf("%d", 123456677);
// 	printf("\n");
// 	ft_printf("%d", 111111113456111677);
// 	printf("\n");
// 	ft_printf("%s", "1222121213456677");
// 	printf("\n");
// 	ft_printf("%s%s%d", "-1222121213456677 ", "salut les zgueg ", 444);
// 	printf("\n");
// 	ft_printf("%x",5555);
// 	printf("\n");
// 	ft_printf("%p", 100000000);
// 	printf("\n");
	

// }