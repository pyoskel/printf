/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_ons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:19:52 by pabartoc          #+#    #+#             */
/*   Updated: 2026/10/27 21:12:45 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = (write(1, &c, 1));
	return (counter);
}

int	ft_putstr(char *str)
{
	int	counter;
	int	write_check;

	if (!str)
		return (ft_putstr("(null)"));
	counter = 0;
	while (str[counter] != '\0')
	{
		write_check = write(1, &str[counter], 1);
		if (write_check == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

int	ft_putptr(void *ptr, int flag)
{
	unsigned long	address;
	int				counter;
	int				temp;

	address = (unsigned long)ptr;
	counter = 0;
	if (flag == 0)
	{
		if (!ptr)
			return (write(1, PTRNULL, PTRSIZE));
		if (write(1, "0x", 2) == -1)
			return (-1);
		counter += 2;
	}
	if (address >= 16)
	{
		temp = ft_putptr((void *)(address / 16), 1);
		if (temp == -1)
			return (-1);
		counter += temp;
	}
	if (write(1, &HEXALOWER[address % 16], 1) == -1)
		return (-1);
	return (counter + 1);
}

int	ft_putnbr(int nbr, unsigned int base)
{
	int		counter;
	int		temp;

	counter = 0;
	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		counter ++;
		nbr = -nbr;
	}
	if (nbr >= (int)base)
	{
		temp = ft_putnbr(nbr / base, base);
		if (temp == -1)
			return (-1);
		counter += temp;
	}
	if (write(1, &BASE10[nbr % base], 1) == -1)
		return (-1);
	return (counter + 1);
}

int	ft_puthex_or_u(unsigned int nbr, char c, unsigned int base)
{
	int		counter;
	char	hexadec;
	int		temp;

	counter = 0;
	if (nbr >= base)
	{
		temp = ft_puthex_or_u(nbr / base, c, base);
		if (temp == -1)
			return (-1);
		counter += temp;
	}
	if (c == 'X')
		hexadec = HEXAUPPER[nbr % base];
	else
		hexadec = HEXALOWER[nbr % base];
	temp = write(1, &hexadec, 1);
	if (temp == -1)
		return (-1);
	counter += temp;
	return (counter);
}

// int main(void) // ft_putchar
// {
// 	// ft_printf(" %c %c %c \n", '0', 0, '1');
// 	// ft_printf("%c %c \n", '1', '2');
// 	// printf("\n");
// 	int i = ft_printf("%c %c  abc", 'A', 'B');
// 	printf("\n%d\n", i);
// 	return (0);
// }

// int main(void) // ft_putstr
// {
// 	// int count = 0;

// 	// // Hier übergeben wir den echten NULL-Zeiger (0x0)
//     // // ft_printf sieht: str ist 0 -> springt in dein if (!str)
//     // count = ft_printf("%s", NULL);
//     // printf("\nMy-Return-Wert: %d\n", count);
//     // count = printf("%s", (char *)NULL);
//     // printf("\nprintf-Return-Wert: %d\n", count);

// 	printf("hallo %s!\n", "world");
// 	ft_printf("hallo %s!\n", "world");
// 	return (0);
// }

// int main(void) // ft_putstr mit NULL testen
// {
//     int count_null;
//     char *null_ptr = NULL; // Definiert einen echten Null-Pointer

//     ft_printf("--- Test: %%s mit NULL ---\n");

//     // Testen der ft_printf Funktion
//     // Sie sollte "ft_printf (null)" ausgeben.
//     // Gedruckte Zeichen: "ft_printf " (10) + "(null)" (6) = 16
//     count_null = ft_printf("%s", null_ptr); 
//     ft_printf(" | ft_printf Return-Wert: %d\n", count_null);

//     // Vergleich mit dem Standard-printf (optional)
//     int std_count_null = printf("%s", null_ptr);
//     printf(" | Original printf Return-Wert: %d\n", std_count_null);

//     return (0);
// }

// int main(void) // ft_putptr
// {
//     int count;
//     void *ptr = (void *)0xDEADBEEF; // Ein Beispiel-Pointer

//     // Test
//     count = ft_printf("Test:	  %p | %p\n", ptr, NULL);
//     printf("Original: %p | %p | (count: %d)\n", ptr, NULL, count);

//     return 0;
// }

// int	main(void) // ft_putnbr
// {
// 	printf("%d\n", INT_MIN);
// 	ft_printf("%d\n", INT_MIN);
// 	return (0);
// }

// int	main(void)	// ft_puthex_or_u
// {
// 	int				number1 = 255;
// 	int				number2 = 0;
// 	unsigned int	number3 = 4294967295;

// 	printf("Lowercase hex (x): %x\n", number1);
// 	ft_printf("Lowercase hex (x): %x\n\n", number1); // Erwartet: "ff"

// 	printf("Uppercase hex (X): %X\n", number1);
// 	ft_printf("Uppercase hex (X): %X\n\n", number1); // Erwartet: "FF"

// 	printf("Hex von 0: %x\n", number2);
// 	ft_printf("Hex von 0: %x\n\n", number2); // Erwartet: "0"

// 	// Erwartet: "ffffffff"
// 	printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	ft_printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	return (0);
// }
