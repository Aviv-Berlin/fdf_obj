/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:58 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 17:30:01 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*result;
	char		*temp;
	size_t		index;

	if (!s || !f)
		return (NULL);
	result = (char *) malloc((ft_strlen(s) + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	temp = result;
	index = 0;
	while (*s)
	{
		*temp = f(index, *s);
		s++;
		temp++;
		index++;
	}
	*temp = '\0';
	return (result);
}
