/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:58 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 17:30:01 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f (index, &s[index]);
		index++;
	}
}
/*
void temp_uppercase(unsigned int index, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 32; // Convert to uppercase
    }
}


int main()
{
	char s[] = "test test";
	ft_striteri(s, temp_uppercase);
	printf("%s\n", s);
}*/