/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.dE     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:25:04 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/07 12:25:11 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if (result)
		return (result);
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}
/*


int	main()
{
	char *string = "bounjour";
	char	c = '\0';
	char	*result = ft_strrchr(string, c);
	printf("%s\n", result);
}*/