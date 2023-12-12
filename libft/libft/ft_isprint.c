/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:14:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:35 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isprint(int c);

// DESCRIPTION
//	The isprint() function tests for any printing character, 
//	including space (` '). The value of the argument must be
//	representable as an unsigned char or the value of EOF.

// RETURN VALUES
//	The isprint() function returns zero if the character tests false 
//	and returns non-zero if the character tests true.

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
