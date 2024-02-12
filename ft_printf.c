/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:54:03 by elefonta          #+#    #+#             */
/*   Updated: 2024/02/12 15:09:06 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arguments;
	int		count;

	count = 0;
	i = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_args(format[i], arguments, format);
			i++;
		}
		else
		{
			count += ft_print_char(format[i]);
			i++;
		}
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
				LOWER_HEX, format, type));
	if (type == 'X')
		return (ft_print_nbr_base(va_arg(argument, unsigned int),
				UPPER_HEX, format, type));
	if (type == 'p')
		return (ft_print_nbr_base((unsigned long long)va_arg(argument, void *),
				LOWER_HEX, format, type));
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

    printf("Bonjour %s, il y a %i points\nTu veux %d bananes?\nHehe %% LOL \nOn tente %u,\nMaintenant, on va voir les x : %x voilà \nMaintenant, on voit les X : %X\n voici les p %p", nom, nombre, nbr, test, testx, testxe, NULL);
	ft_printf("Bonjour %s, il y a %i points\nTu veux %d bananes?\nHehe %% LOL \nOn tente %u,\nMaintenant, on va voir les x : %x voilà \nMaintenant, on voit les X : %X\n voici les p %p", nom, nombre, nbr, test, testx, testxe, NULL);
    return 0;
}