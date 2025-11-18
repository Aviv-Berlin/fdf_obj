/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:55 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/26 11:40:59 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		index;
	int		counter;
	va_list	args;

	index = 0;
	counter = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '%')
				counter += p_char('%');
			else
				counter += sort_specifiers(args, format[index]);
		}
		else
			counter += p_char(format[index]);
		index++;
	}
	va_end(args);
	return (counter);
}

int	sort_specifiers(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += p_char(va_arg(args, int));
	else if (c == 's')
		counter += p_str(va_arg(args, char *));
	else if (c == 'p')
		counter += p_pointer(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		counter += p_nbr(va_arg(args, int), c, 0);
	else if (c == 'u' || c == 'x' || c == 'X')
		counter += p_nbr(va_arg(args, unsigned int), c, 0);
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		counter += 2;
	}
	return (counter);
}

size_t	s_length(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
