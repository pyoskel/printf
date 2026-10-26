/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:30:02 by pabartoc          #+#    #+#             */
/*   Updated: 2025/11/22 01:30:27 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdio.h>  //for printf function
# include <stdarg.h> //for variadic functions
# include <unistd.h> //for write function
# include <limits.h> //for INT_MIN 

# define HEXALOWER "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define PTRSIZE 5
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define PTRSIZE 3
# endif

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr, int flag);
int	ft_putnbr(int nbr, unsigned int base);
int	ft_puthex_or_u(unsigned int nbr, char c, unsigned int base);

#endif