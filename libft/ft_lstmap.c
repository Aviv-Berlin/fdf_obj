/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lstmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:12:48 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:12:52 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	t_list	*temp;

	result = NULL;
	temp = NULL;
	if (!lst || ! f)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			del_lst(result, del);
			del(lst->content);
			return (NULL);
		}
		if (!result)
			result = new;
		else
			temp->next = new;
		temp = new;
		lst = lst->next;
	}
	return (result);
}

void	del_lst(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		if (del && lst->content)
			del(lst->content);
		free(lst);
		lst = temp;
	}
}
