/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:10 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 15:53:18 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	if (start < ft_strlen(s))
	{
		while (index < len && s[index + start])
		{
			result[index] = s[index + start];
			index++;
		}
	}
	result[index] = '\0';
	return (result);
}

/*
int main()
{

	char *s =  ft_substr("hola", 500000, 0);
	printf("%s\n", s);
}*/