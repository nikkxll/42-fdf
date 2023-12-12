/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:31:51 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:23 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isalnum(int c);

// DESCRIPTION
//	The isalnum() function tests for any character for which isalpha(3) 
//	or isdigit(3) is true.  The value of the argument
//	must be representable as an unsigned char or the value of EOF.

// RETURN VALUES
//	The isalnum() function returns zero if the character tests 
//	false and returns non-zero if the character tests true.

#include "../libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57))
		|| ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
