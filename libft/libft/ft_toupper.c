/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:19:11 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:18 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int toupper(int c);

// DESCRIPTION
//	The toupper() function converts a lower-case letter to the corresponding 
//	upper-case letter.  The argument must be representable as an unsigned 
//	char or the value of EOF.

//	Although the toupper() function uses the current locale, the toupper_l() 
//	function may be passed a locale directly. See xlocale(3) for more 
//	information.

// RETURN VALUES
//	If the argument is a lower-case letter, the toupper() function returns 
//	the corresponding upper-case letter if there is one; otherwise, the 
//	argument is returned unchanged.

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
