/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:55 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/26 11:40:59 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	p_pointer(void *ptr)
{
	unsigned long long	address;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (p_address(address, 'x', 2));
}

int	p_address(long long n, char c, int counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		counter++;
		n = n * -1;
	}
	if (n >= 16)
	{
		counter = p_address((n / 16), c, counter);
	}
	counter++;
	write (1, &base[(n % 16)], 1);
	return (counter);
}

int	p_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	p_str(char *str)
{
	int	length;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = s_length(str);
	write(1, str, length);
	return (length);
}

int	p_nbr(long n, char c, int counter)
{
	char	*base;
	int		base_len;

	base = "0123456789";
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	base_len = s_length(base);
	if (n < 0)
	{
		write(1, "-", 1);
		counter++;
		n = n * -1;
	}
	if (n >= base_len)
	{
		counter = p_nbr((n / base_len), c, counter);
	}
	counter++;
	write (1, &base[(n % base_len)], 1);
	return (counter);
}
