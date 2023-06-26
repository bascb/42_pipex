/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:21:27 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/10 18:27:44 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the unsigned int n to given fd */
void	ft_putunsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
		ft_putunsigned_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
