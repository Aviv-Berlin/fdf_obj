/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:42 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:16:45 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		index;

	if (!dest && !src)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (const char *)src;
	if (temp_dest > temp_src && (temp_src + n) > temp_dest)
	{
		while (n--)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		index = 0;
		while (index < n)
		{
			temp_dest[index] = temp_src[index];
			index++;
		}
	}
	return (dest);
}
