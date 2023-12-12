/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:57:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:58 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstnew

// Prototype: t_list *ft_lstnew(void *content);

// Turn in files: -

// Parameters: content: The content to create the node with.

// Return value: The new node

// External functs.: malloc

// Description: Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}
