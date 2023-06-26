/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:12:59 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/24 19:13:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if char (unsigned) is printable
*  
*
* Returns a nonzero if it is and zero if not
*
*/
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
