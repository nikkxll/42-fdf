/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:03:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:48 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstdelone

// Prototype: void ft_lstdelone(t_list *lst, void (*del)(void
// *));

// Turn in files: -

// Parameters: lst: The node to free.
// 			   del: The address of the function used to delete
// the content.

// Return value: None

// External functs.: free

// Description: Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}
