/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcntchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:03:03 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/07 11:03:08 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of occurences 
   of char c in string str */
int	ft_strcntchr(char *str, int c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	if (c > 255)
		c = c % 256;
	while (str[i])
	{
		if (str[i] == (char) c)
			count++;
		i++;
	}
	if (c == '\0')
		count++;
	return (count);
}
