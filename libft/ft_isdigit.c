/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:10:37 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/24 18:11:51 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if char (unsigned) is a digit 
*
* Returns a nonzero if it is a digit, and zero if not
*
*/
int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}
