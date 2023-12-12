/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:32:44 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:40 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstadd_back

// Prototype: void ft_lstadd_back(t_list **lst, t_list *new);

// Turn in files: -

// Parameters: lst: The address of a pointer to the first link of
// a list.
// 			   new: The address of a pointer to the node to be
// added to the list.

// Return value: None

// External functs.: None

// Description: Adds the node ’new’ at the end of the list.

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
