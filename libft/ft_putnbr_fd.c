/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:05:24 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/31 18:05:26 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_r(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
		ft_putnbr_r(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

/* Outputs the integer n to given fd */
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_r(-n, fd);
	}
	else
		ft_putnbr_r(n, fd);
}
