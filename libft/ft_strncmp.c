/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.dE     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:25:04 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/07 12:25:11 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main()
{
	int result = ft_strncmp("test\200", "test\0", 6);
	printf("%d\n", result);
}*/