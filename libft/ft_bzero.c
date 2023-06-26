/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:16:27 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/25 18:36:17 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Erases the data in n bytes of buffer */
void	ft_bzero(void *buffer, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *) buffer;
	while (i < n)
		b[i++] = 0;
}
