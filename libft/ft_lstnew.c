/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:12:48 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:12:52 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newitem;

	newitem = (t_list *)malloc(sizeof(t_list));
	if (newitem == NULL)
		return (NULL);
	newitem->content = content;
	newitem->next = NULL;
	return (newitem);
}
