/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:41:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:26 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isalpha(int c);

// DESCRIPTION
//	The isalpha() function tests for any character for which isupper(3) 
//	or islower(3) is true.  The value of the argument
//	must be representable as an unsigned char or the value of EOF.

// RETURN VALUES
//	The isalpha() function returns zero if the character tests false and 
//	returns non-zero if the character tests true.

#include "../libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
