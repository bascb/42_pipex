/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:43:05 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/07 11:43:11 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if char c belongs to charset 
	Returns 1 if true and 0 if false */
int	ft_charinset(int c, char *charset)
{
	size_t	i;

	i = 0;
	if (c > 255)
		c = c % 256;
	while (charset[i])
	{
		if (charset[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}
