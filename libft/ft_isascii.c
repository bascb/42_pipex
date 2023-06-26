/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:11:37 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/24 19:13:14 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if char (unsigned) s a 
* 7-bit unsigned char value that fits into 
the ASCII character set. 
*
* Returns a nonzero if it is and zero if not
*
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
