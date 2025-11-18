/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:42 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:16:45 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		temp_s1++;
		temp_s2++;
		n--;
	}
	return (0);
}
/*
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	if (n == 0)
		return (0);
	index = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (index < n && *temp_s1 && *temp_s2 && *temp_s1 == *temp_s2)
	{
		temp_s1++;
		temp_s2++;
		index++;
	}
	if (index == n)
		return (0);
	return (*temp_s1 - *temp_s2);
}
*/
/*
int main()
{
	char arr1[] = {1, 2, 5, 4, 5};
	char arr2[] = {1, 2, 5, 4, 5};
	int result = ft_memcmp(arr1, arr2, 5);
	printf("%d\n", result);
}*/