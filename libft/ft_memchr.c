/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:14:13 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/28 12:52:26 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the first occurrence of unsigned char c
   in first n bytes of memory buffer */
void	*ft_memchr(const void *buffer, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *) buffer == (unsigned char) c)
			return ((void *) buffer);
		buffer++;
		i++;
	}
	return (NULL);
}
