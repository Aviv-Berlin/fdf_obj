/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:25:04 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/07 12:25:11 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

/*
int main()
{
	char *s1 = "aviv2";
	char *s2 = "aviv5";
	int my_result = ft_strncmp(s1, s2, 2);
	int original = strncmp(s1, s2, 2);
	printf("my %d, original %d\n", my_result, original);
}*/