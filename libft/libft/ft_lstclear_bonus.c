/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:13:49 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:45 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstclear

// Prototype void ft_lstclear(t_list **lst, void (*del)(void
// *));

// Turn in files: -

// Parameters: lst: The address of a pointer to a node.
// 			   del: The address of the function used to delete
// the content of the node.

// Return value: None

// External functs.: free

// Description: Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
