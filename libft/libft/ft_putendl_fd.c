/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:29:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:34 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putendl_fd(char *s, int fd);

// Turn in files: -

// Parameters: s: The string to output.
// 			   fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the string ’s’ to the given file descriptor
// followed by a newline.

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
