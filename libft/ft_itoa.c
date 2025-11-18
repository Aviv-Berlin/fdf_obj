/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:58 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 17:30:01 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;

	if (n > 0)
		return (above_zero(n));
	else if (n == 0)
	{
		number = (char *) malloc(2 * sizeof (char));
		if (number == NULL)
			return (NULL);
		number[0] = 0 + '0';
		number[1] = '\0';
		return (number);
	}
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (below_zero(n));
}

char	*below_zero(int n)
{
	char			*number;
	int				digits;
	int				temp;

	n = n * -1;
	digits = digit_count(n);
	temp = digits;
	number = (char *) malloc((digits + 2) * sizeof (char));
	if (number == NULL)
		return (NULL);
	while (n > 0)
	{
		number[digits] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	number[0] = '-';
	number[temp + 1] = '\0';
	return (number);
}

/*
char	*zero(void)
{
	char	*number;

	number = (char *) malloc(2 * sizeof (char));
	if (number == NULL)
		return (NULL);
	number[0] = 0 + '0';
	number[1] = '\0';
	return (number);
}
*/
char	*above_zero(int n)
{
	char	*number;
	int		digits;
	int		temp;

	digits = digit_count(n);
	temp = digits;
	number = (char *) malloc((digits + 1) * sizeof (char));
	if (number == NULL)
		return (NULL);
	while (n > 0)
	{
		number[digits -1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	number[temp] = '\0';
	return (number);
}

int	digit_count(int n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}
/*
int main(void)
{
	char *number = ft_itoa(12354687);
	printf("%s\n", number);
}
*/