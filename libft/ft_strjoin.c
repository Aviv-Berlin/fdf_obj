/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c 		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:10 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 15:53:18 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	index;

	result = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (*s1)
	{
		result[index] = *s1;
		s1++;
		index++;
	}
	while (*s2)
	{
		result[index] = *s2;
		s2++;
		index++;
	}
	result[index] = '\0';
	return (result);
}
/*
int	main()
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;
	strjoin = ft_strjoin(s1, s2);
	printf("%s\n", strjoin);
}*/
