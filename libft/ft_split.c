/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:58 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 17:30:01 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**result;

	if (!s)
		return (NULL);
	size = count_delim(s, c);
	result = malloc((size + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (populate(result, s, c, size));
}

char	**populate(char **result, char const *s, char c, int size)
{
	int		index;
	int		flag;

	index = 0;
	flag = 0;
	while (*s && index < size)
	{
		if (*s != c && flag == 0)
		{
			result[index] = strdup_delim(s, c);
			if (result[index] == NULL)
			{
				free_array(result, index);
				return (NULL);
			}
			index++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	result[index] = NULL;
	return (result);
}

void	free_array(char **result, int index)
{
	int	counter;

	counter = 0;
	while (counter <= index)
	{
		free(result[counter]);
		counter++;
	}
	free(result);
}

char	*strdup_delim(char const *s, char c)
{
	char	*dest;
	int		length;
	int		index;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	dest = (char *) malloc((length + 1) * sizeof (char));
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dest[index] = *s;
		s++;
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	count_delim(char const *s, char c)
{
	int	flag;
	int	counter;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}
/*
int	main()
{
	char *string = "  aviv   kosloff stuck strasse  ";
	char c = ' ';
	int counter = 0;
	char **result = ft_split(string, c);
	while (result[counter] != NULL)
	{
		printf("%s\n", result[counter]);
		counter++;
	}
	counter = 0;
	while (result[counter] != NULL)
	{
		free(result[counter]);
		counter++;
	}
	free (result);
}
*/