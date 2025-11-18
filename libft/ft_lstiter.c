/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lstiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:12:48 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:12:52 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || ! f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main()
{
	// Create nodes for the linked list
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	// Link the nodes
	node1->next = node2;
	node2->next = node3;

	// Test the ft_lstiter function
	printf("Applying print_content to each node:\n");
	ft_lstiter(node1, print_content);

	// Free the allocated memory
	free(node1);
	free(node2);
	free(node3);

	return 0;
}
*/
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

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
}*/