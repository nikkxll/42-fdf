/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:27:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:39 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putstr_fd(char *s, int fd);

// Turn in files: -

// Parameters s: The string to output.
// 			  fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the string ’s’ to the given file
// descriptor.

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
	}
}
