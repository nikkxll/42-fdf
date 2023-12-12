/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:25:39 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:21 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putchar_fd(char c, int fd);

// Turn in files: -

// Parameters: c: The character to output.
//			   fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the character ’c’ to the given file
// descriptor.

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
