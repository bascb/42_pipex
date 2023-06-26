/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:43:11 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/24 20:05:02 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills the first n bytes of buffer wtih c */
void	*ft_memset(void *buffer, int c, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *) buffer;
	while (i < n)
		b[i++] = c;
	return (buffer);
}
