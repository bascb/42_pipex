/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_base_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:23:35 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/10 22:06:55 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	ft_check_base(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]) || ft_strcntchr(base, base[i]) > 1)
			return (0);
		i++;
	}
	return (i);
}

static void	ft_putunsigned_base_r(unsigned int n,
		int fd, char *base, unsigned int size)
{
	char	c;

	if (n >= size)
		ft_putunsigned_base_r(n / size, fd, base, size);
	c = base[n % size];
	write(fd, &c, 1);
}

/* Converts the unsigned integer to base and outputs it to given fd 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
void	ft_putunsigned_base_fd(unsigned int n, char *base, int fd)
{
	unsigned int	base_size;

	base_size = ft_check_base(base);
	if (base_size < 2)
		return ;
	ft_putunsigned_base_r(n, fd, base, base_size);
}
