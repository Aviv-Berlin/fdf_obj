/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:15:08 by akosloff          #+#    #+#             */
/*   Updated: 2024/12/04 12:15:16 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = get_strlen(s1);
	s2_len = get_strlen(s2);
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (s1 && *s1)
		result[index++] = *s1++;
	while (s2 && *s2)
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}

size_t	get_strlen(const char *s)
{
	int	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*get_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	s_len;

	s_len = get_strlen(s);
	if (!s)
		return (NULL);
	if (start + len > s_len)
		len = s_len - start;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < len)
		result[index++] = s[start++];
	result[index] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
